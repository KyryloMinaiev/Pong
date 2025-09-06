export module Container;

import ContainerType;
import IUpdatable;
import IInitializable;
import IInstaller;
import ObjectsModule;

import <vector>;
import <map>;
import <string>;
import <typeindex>;
import <memory>;
import <iostream>;

export class Container
{
public:
    template <typename TValue>
    struct BindContainer
    {
        BindContainer(TValue* value, Container* container);

        ~BindContainer() = default;
        std::vector<std::type_index> getRegisteredTypes();
        operator TValue*();

        TValue* registerType();

        template <typename TType>
        BindContainer& asType();

    private:
        Container* m_container;
        TValue* m_value;
        std::vector<std::type_index> m_registeredTypes;
    };

    Container();
    void setupObjectsFactory(ObjectFactory* factory);

    template <typename TValue>
    TValue* registerBindContainer(BindContainer<TValue>& bind_container);

    template <typename TValue>
    BindContainer<TValue> bind();

    template <typename TValue>
    TValue* resolve();

    void update(float deltaTime) const;

    template <typename TValue, typename TType>
    void registerObjectAsType(TValue* value);

    template <typename TValue>
    void registerObject(TValue* value);

    template <typename TInstaller>
        requires std::is_base_of_v<IInstaller<TInstaller>, TInstaller>
    void install();

    template <typename TObject>
        requires std::is_base_of_v<Object, TObject>
    TObject* instantiate(const std::string& name = std::string(), bool active = true);

private:
    template <typename TValue>
    TValue* createInternal();

    template <typename TValue>
    void injectDependencies(TValue&)
    {
    }

    template <typename TValue>
        requires requires(TValue t) { &TValue::inject; }
    void injectDependencies(TValue& instance);

    template <typename TValue, typename... Args>
    void callInject(TValue& instance, void (TValue::*test)(Args...));

    template <typename TValue>
    void addUpdatable(TValue* instance);

    template <typename TValue>
    static void addInitializable(TValue* instance);

    void tryAddType(size_t typeHash, const std::string& typeName, void* value);

    std::vector<std::shared_ptr<void>> m_registeredTypes;
    std::map<size_t, void*> m_registeredTypesMap;
    std::vector<IUpdatable*> m_updatables;

    ObjectFactory* m_objectFactory;
};

template <typename TValue>
Container::BindContainer<TValue>::BindContainer(TValue* value, Container* container) : m_container(container),
m_value(value)
{
}

template <typename TValue>
std::vector<std::type_index> Container::BindContainer<TValue>::getRegisteredTypes()
{
    return m_registeredTypes;
}

template <typename TValue>
Container::BindContainer<TValue>::operator TValue* ()
{
    return m_value;
}

template <typename TValue>
TValue* Container::BindContainer<TValue>::registerType()
{
    m_container->registerBindContainer(*this);
    return m_value;
}

template <typename TValue>
template <typename TType>
Container::BindContainer<TValue>& Container::BindContainer<TValue>::asType()
{
    auto type_id = std::type_index(typeid(TType));
    if (std::find(m_registeredTypes.begin(), m_registeredTypes.end(), type_id) == m_registeredTypes.end())
    {
        m_registeredTypes.push_back(type_id);
    }

    return *this;
}

template <typename TValue>
TValue* Container::registerBindContainer(BindContainer<TValue>& bind_container)
{
    TValue* value = bind_container;

    if (bind_container.getRegisteredTypes().empty())
    {
        auto& type_id = typeid(TValue);
        tryAddType(type_id.hash_code(), type_id.name(), value);
    }
    else
    {
        for (auto& type : bind_container.getRegisteredTypes())
        {
            auto hash_code = type.hash_code();
            tryAddType(hash_code, type.name(), value);
        }
    }

    addInitializable(value);
    addUpdatable(value);

    return bind_container;
}

template <typename TValue>
Container::BindContainer<TValue> Container::bind()
{
    TValue* value = createInternal<TValue>();
    return BindContainer<TValue>(value, this);
}

template <typename TValue>
TValue* Container::resolve()
{
    auto& type_info = typeid(TValue);
    auto it = m_registeredTypesMap.find(type_info.hash_code());
    if (it == m_registeredTypesMap.end())
    {
        std::cout << "Type " << type_info.name() << " not registered!" << std::endl;
        return nullptr;
    }

    return static_cast<TValue*>(it->second);
}

template <typename TValue, typename TType>
void Container::registerObjectAsType(TValue* value)
{
    auto& type_id = typeid(TType);
    tryAddType(type_id.hash_code(), type_id.name(), value);
}

template <typename TValue>
void Container::registerObject(TValue* value)
{
    auto& type_id = typeid(TValue);
    tryAddType(type_id.hash_code(), type_id.name(), value);
}

template <typename TInstaller>
    requires std::is_base_of_v<IInstaller<TInstaller>, TInstaller>
void Container::install()
{
    TInstaller installer = TInstaller();
    installer.install(this);
}

template <typename TObject> requires std::is_base_of_v<Object, TObject>
TObject* Container::instantiate(const std::string& name, bool active)
{
    TObject* object = m_objectFactory->createObjectOfType<TObject>(name, active);
    injectDependencies(*object);
    return object;
}

template <typename TValue>
TValue* Container::createInternal()
{
    auto shared_ptr = std::make_shared<TValue>();
    injectDependencies(*shared_ptr.get());
    m_registeredTypes.push_back(shared_ptr);
    return shared_ptr.get();
}

template <typename TValue> requires requires(TValue t) { &TValue::inject; }
void Container::injectDependencies(TValue& instance)
{
    callInject(instance, &TValue::inject);
}

template <typename TValue, typename... Args>
void Container::callInject(TValue& instance, void (TValue::* test)(Args...))
{
    instance.inject(resolve<std::remove_pointer_t<Args>>()...);
}

template <typename TValue>
void Container::addUpdatable(TValue* instance)
{
    if (IUpdatable* updatable = dynamic_cast<IUpdatable*>(instance))
    {
        m_updatables.push_back(updatable);
    }
}

template <typename TValue>
void Container::addInitializable(TValue* instance)
{
    if (IInitializable* initializable = dynamic_cast<IInitializable*>(instance))
    {
        initializable->initialize();
    }
}
