#pragma once
#include <exception>
#include <stdexcept>

template<typename T>
class ListNode
{
public:
    ListNode(const  ListNode<T>&) = delete;
    ListNode(ListNode<T>&&) = delete;
    ListNode<T>& operator=(const  ListNode<T>&) = delete;
    ListNode<T>& operator=(ListNode<T>&&) = delete;

    ListNode<T>* _next;
    T _value;

    ListNode(ListNode<T>* next = nullptr, T value = T())
    {
        _next = next;
        _value = value;
    }
};


template<typename T>
class ForwardList
{
public:
    ForwardList();

    ~ForwardList();

    ForwardList(const ForwardList<T>& copying);

    ForwardList(ForwardList<T>&& transfer);

    void clear() noexcept;

    ListNode<T>* insert_after(ListNode<T>* where, const T& value);

    void push_back(const T& value);

    void push_front(const T& value);

    void remove(const T& value);

    ListNode<T>* first();

    ListNode<T>* last();

    T get(size_t position);

    bool empty() const noexcept;

    void reverse() noexcept;

    size_t size() const;

    friend bool operator==(const ForwardList<T>& left, const ForwardList<T>& right)
    {
        if (left.size() != right.size())
            throw std::length_error("You can't compare objects with different size");
        else
        {
            ForwardList<T> fir = left;
            ForwardList<T> sec = right;
            for (size_t i = 0; i < fir.size(); ++i)
            {
                if (fir.get(i) != sec.get(i))
                    return false;
            }
        }
        return true;
    }

    friend bool operator!=(const ForwardList<T>& left, const ForwardList<T>& right)
    {
        // Мб все-таки return !(left == right); ?
        return !(left == right);
    }

private:
    ListNode<T>* _head;
};


template<typename T>
ForwardList<T>::ForwardList()
{
    _head = nullptr;
}

template<typename T>
ForwardList<T>::~ForwardList()
{
    clear();
}

template<typename T>
ForwardList<T>::ForwardList(const ForwardList<T>& copyNode)
{
    ListNode<T>* current = copyNode._head;

    while (current != nullptr)
    {
        this->push_back(current->_value);

        current = current->_next;
    }
}

template<typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& transfer) : _head(transfer._head)
{
    transfer._head = nullptr;
}

template<typename T>
void ForwardList<T>::clear() noexcept
{
    while (_head != nullptr)
    {
        ListNode<T>* temp = _head;

        _head = _head->_next;

        delete temp;
    }
}

template<typename T>
ListNode<T>* ForwardList<T>::insert_after(ListNode<T>* where, const T& value)
{
    ListNode<T>* newItem;

    if (where == nullptr)
    {
        newItem = new ListNode<T>(_head, value);

        return newItem;
    }
    newItem = new ListNode<T>(where->_next, value);

    where->_next = newItem;

    return newItem;
}

template<typename T>
void ForwardList<T>::push_back(const T& value)
{
    if (_head == nullptr)
    {
        _head = new ListNode<T>(nullptr, value);
    }
    else
    {
        ListNode<T>* current = _head;

        while (current->_next != nullptr)
        {
            current = current->_next;
        }

        current->_next = insert_after(current, value);
    }
}

template<typename T>
void ForwardList<T>::push_front(const T& value)
{
    _head = insert_after(nullptr, value);
}

template<typename T>
void ForwardList<T>::remove(const T& value)
{
    ListNode<T>* toRemove;
    if (_head->_value == value)
    {
        ListNode<T>* toRemove = _head;

        _head = _head->_next;

        delete toRemove;
    }
    else
    {
        ListNode<T>* previous = _head;

        while (previous->_next->_value != value)
        {
            previous = previous->_next;
        }

        toRemove = previous->_next;

        previous->_next = toRemove->_next;

        delete toRemove;
    }
}

template<typename T>
ListNode<T>* ForwardList<T>::first()
{
    if (_head == nullptr)
        throw std::runtime_error("ForwardList head is nullptr /add smth to it");
    return _head;
}

template<typename T>
ListNode<T>* ForwardList<T>::last()
{
    if (_head == nullptr)
        throw std::runtime_error("ForwardList head is nullptr /add smth to it");

    ListNode<T>* temp = _head;

    while (temp->_next != nullptr)
    {
        temp = temp->_next;
    }
}

template<typename T>
T ForwardList<T>::get(size_t position)
{
    size_t count = 0;

    ListNode<T>* temp = _head;

    while (temp != nullptr)
    {
        if (count == position)
            return temp->_value;

        temp = temp->_next;

        count++;
    }

    throw std::out_of_range("Position out of correct diaposon");
}

template<typename T>
bool ForwardList<T>::empty() const noexcept
{
    return _head == nullptr;
}

template<typename T>
void ForwardList<T>::reverse() noexcept
{
    size_t size = this->size();

    T last = this->get(size-1);

    this->remove(last);

    this->push_front(last);

    ListNode<T>* temp = _head;

    for (size_t i = 0; i < size-1; ++i)
    {
        T last = this->get(size-1);

        this->remove(last);

        this->insert_after(temp, last);

        temp = temp->_next;
    }
}

template<typename T>
size_t ForwardList<T>::size() const
{
    size_t counter = 0;

    ListNode<T>* temp = _head;

    while (temp != nullptr)
    {
        temp = temp->_next;
        counter++;
    }

    return counter;
}
