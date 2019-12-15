#pragma once
#include <iostream>

template <typename Type, size_t size>
class Stack
{
public:
    Stack();
    ~Stack() {}

    bool push(Type* item); // insert item into stack
    Type* pop(); // return and remove top item of the stack // pointer zurückgeben um nullptr 
    Type* peek(); // return top item of the stack without removing it
    bool isFull(); // check if item count has reached max
    bool isEmpty(); // check if top is nullptr
    void print(); // for debugging
    void clear(); // delete all elements
    Type* operator[](int index); // access element via index
    int getCount() { return elementCount; }

private:
    int elementCount = 0;
    Type* _stack;
    Type* _top;
};

template <typename Type, size_t size>
Stack<Type, size>::Stack()
{
    _stack = new Type[sizeof(Type) * size]; // allocating memory
    _top = _stack;
}

template <typename Type, size_t size>
bool Stack<Type, size>::push(Type* item)
{
    if (isEmpty())
    {
        elementCount++;
        *_top = *item;
        return true;
    }
    else if (!isEmpty() && !isFull())
    {
        elementCount++;
        _top += sizeof(Type);
        *_top = *item;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Type, size_t size>
Type* Stack<Type, size>::pop()
{
    if (!isEmpty())
    {
        elementCount--;
        auto item = _top;
        memset(_top, NULL, sizeof(Type));
        _top -= sizeof(Type);
        return item;
    }
    return nullptr;
}

template <typename Type, size_t size>
Type* Stack<Type, size>::peek()
{
    if (!isEmpty())
    {
        return _top;
    }
    return nullptr;
}

template <typename Type, size_t size>
bool Stack<Type, size>::isFull()
{
    return elementCount == size;
}

template <typename Type, size_t size>
bool Stack<Type, size>::isEmpty()
{
    return elementCount == 0;
}

template <typename Type, size_t size>
void Stack<Type, size>::print()
{
    for (int i = 0; i < elementCount; i++)
        std::cout << *(_top - i * sizeof(Type)) << std::endl;
}

template <typename Type, size_t size>
void Stack<Type, size>::clear()
{
    memset(_stack, NULL, sizeof(Type) * size);
    _top = _stack;
}

template<typename Type, size_t size>
inline Type* Stack<Type, size>::operator[](int index)
{
    if (index <= elementCount)
        return &(_stack + sizeof(Type) * index);
    return nullptr;
}
