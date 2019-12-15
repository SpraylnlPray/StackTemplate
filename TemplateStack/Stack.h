#pragma once
#include <iostream>

template <typename Type, size_t size>
class Stack
{
public:
    Stack()
    {
        _stack = new Type[sizeof(Type) * size]; // allocating memory
        _top = _stack;
    }
    ~Stack() {}

    // insert item into stack
    bool push(Type* item) 
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
    // return and remove top item of the stack
    Type* pop() 
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
    // return top item of the stack without removing it
    Type* peek()
    {
        if (!isEmpty())
        {
            return _top;
        }
        return nullptr;
    }
    // check if item count has reached max
    bool isFull() { return elementCount == size; }
    // check if top is nullptr
    bool isEmpty() { return elementCount == 0; } 
    // for debugging
    void print()
    {
        for (int i = 0; i < elementCount; i++)
            std::cout << *(_top - i * sizeof(Type)) << std::endl;
    }
    // delete all elements
    void clear()
    {
        memset(_stack, NULL, sizeof(Type) * size);
        _top = _stack;
    }
    // access element via index
    Type* operator[](int index)
    {
        if (index <= elementCount)
            return (_stack + sizeof(Type) * index);
        return nullptr;
    }
    // get number of elements
    int getCount() { return elementCount; }

private:
    int elementCount = 0;
    Type* _stack;
    Type* _top;
};
