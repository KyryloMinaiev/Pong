#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <typeindex>

class Container
{
public:
    template <typename TValue>
    struct BindContainer
    {
        BindContainer(TValue* value, Container* container);

        ~BindContainer() = default;
        std::vector<std::type_index> getRegisteredTypes();
        operator TValue*();

        void registerType();

        template <typename TType>
        BindContainer& asType();

    private:
        Container* m_container;
        TValue* m_value;
        std::vector<std::type_index> m_registeredTypes;
    };

    Container();

    template <typename TValue>
    TValue* registerBindContainer(BindContainer<TValue>& bind_container);

    template <typename TValue>
    BindContainer<TValue> bind();

    template <typename TValue>
    TValue* resolve();

private:
    template <typename TValue>
    TValue* createInternal();

    template <typename TValue>
    void injectDependencies(TValue&) { }

    template <typename TValue>
        requires requires(TValue t) { &TValue::inject; }
    void injectDependencies(TValue& instance);

    template <typename TValue, typename... Args>
    void callInject(TValue& instance, void (TValue::*test)(Args...));

    std::vector<std::shared_ptr<void>> m_registeredTypes;
    std::map<size_t, void*> m_registeredTypesMap;
};

template <typename TValue>
Container::BindContainer<TValue>::BindContainer(TValue* value, Container* container) : m_container(container),
    m_value(value)
{
}

template <typename TValue>
std::vector<std::type_index> Container::BindContainer<TValue>::getRegisteredTypes()
{
    return std::move(m_registeredTypes);
}

template <typename TValue>
Container::BindContainer<TValue>::operator TValue*()
{
    return m_value;
}

template <typename TValue>
void Container::BindContainer<TValue>::registerType()
{
    m_container->registerBindContainer(*this);
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
    for (auto& type : bind_container.getRegisteredTypes())
    {
        auto hash_code = type.hash_code();
        if (m_registeredTypesMap.find(hash_code) != m_registeredTypesMap.end())
        {
            std::cout << "Type " << type.name() << " already registered!" << std::endl;
        }
        else
        {
            m_registeredTypesMap[hash_code] = bind_container;
        }
    }

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
void Container::callInject(TValue& instance, void (TValue::*test)(Args...))
{
    instance.inject(resolve<std::remove_pointer_t<Args>>()...);
}
