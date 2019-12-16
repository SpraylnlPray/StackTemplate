#pragma once
#include <iostream>

template <typename Type, size_t size>
class Stack
{
public:
    Stack()
    {
        _stack = new Type*[size]; // allocating memory
    }
    ~Stack() {}

    // insert item into stack
    bool push(Type* item) 
    {
        if (isEmpty())
        {
            _stack[elementCount] = item;
            elementCount++;
            return true;
        }
        else if (!isEmpty() && !isFull())
        {
            _stack[elementCount] = item;
            elementCount++;
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
            return _stack[elementCount--];
        }
        return nullptr;
    }
    // return top item of the stack without removing it
    Type* peek()
    {
        if (!isEmpty())
        {
            return _stack[elementCount];
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
            std::cout << *_stack[i] << std::endl;
    }
    // delete all elements
    void clear()
    {
        _stack = new Type * [size]; // allocating memory
    }
    // access element via index
    Type* operator[](int index)
    {
        if (index <= elementCount)
            return _stack[index];
        return nullptr;
    }
    // get number of elements
    int getCount() { return elementCount; }

private:
    int elementCount = 0;
    Type** _stack;
};
