export module ReactiveProperty;

import Delegates;

export template <class TValue>
class ReactiveProperty
{
public:
    ReactiveProperty(TValue value);
    ~ReactiveProperty();
    TValue getValue() const;
    void setValue(TValue value);

    void subscribe(Action<TValue> callback);
    void unsubscribe(Action<TValue> callback);
private:
    TValue m_value;
    Event<TValue> m_valueChangedEvent;
};

template <class TValue>
ReactiveProperty<TValue>::ReactiveProperty(TValue value)
{
    m_value = value;
}

template <class TValue>
ReactiveProperty<TValue>::~ReactiveProperty() = default;

template <class TValue>
TValue ReactiveProperty<TValue>::getValue() const
{
    return m_value;  
}

template <class TValue>
void ReactiveProperty<TValue>::setValue(TValue value)
{
    m_value = value;
    m_valueChangedEvent.invoke(value);
}

template <class TValue>
void ReactiveProperty<TValue>::subscribe(Action<TValue> callback)
{
    m_valueChangedEvent.addListener(callback);
    callback(m_value); 
}

template <class TValue>
void ReactiveProperty<TValue>::unsubscribe(Action<TValue> callback)
{
    m_valueChangedEvent.removeListener(callback); 
}
