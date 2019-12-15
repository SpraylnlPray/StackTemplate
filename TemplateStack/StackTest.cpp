#include <iostream>
#include "Stack.h"

int main()
{
    Stack<char, 10> myStack;
    bool isFull = myStack.isFull();
    bool isEmpty = myStack.isEmpty();
    auto var = myStack.peek(); // null
    var = myStack.pop(); // null
    char aChar = 'a';
    myStack.push(&aChar);
    isEmpty = myStack.isEmpty();
    auto val = myStack.peek();
    auto val2 = myStack.pop();
    isEmpty = myStack.isEmpty();
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar);
    myStack.push(&aChar); // false
    myStack.print();
    isFull = myStack.isFull();

    Stack<float, 3> myStack2;
    isFull = myStack2.isFull();
    isEmpty = myStack2.isEmpty();
    float aFloat = 1.234f;
    myStack2.push(&aFloat);
    isEmpty = myStack2.isEmpty();
    myStack2.print();

    Stack<int, 3> myStack3;
    isFull = myStack3.isFull();
    isEmpty = myStack3.isEmpty();
    int anInt = 1000;
    myStack3.push(&anInt);
    myStack3.push(&anInt);
    myStack3.push(&anInt);
    isEmpty = myStack3.isEmpty();
    myStack3.print();
}
