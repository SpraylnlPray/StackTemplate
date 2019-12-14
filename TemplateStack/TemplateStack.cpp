#include <iostream>
#include <typeinfo>

using namespace std;
constexpr auto maxItems = 10;

template <typename Type>
class Stack
{
public:
    Stack();
    ~Stack() {}

    void push(Type item); // insert item into stack
    Type pop(); // return and remove top item of the stack
    Type peek(); // return top item of the stack without removing it
    bool isFull(); // check if item count has reached max
    bool isEmpty(); // check if top is nullptr
    void print(); // for debugging

private:
    int movecount = 0; // for debugging
    Type* stack;
    Type* top;
};

template <typename Type>
Stack<typename Type>::Stack()
{
    stack = new Type[sizeof(Type) * maxItems]; // reserving memory
    memset(top, 0, sizeof(Type) * maxItems);
    top = stack;
}

template <typename Type>
void Stack<typename Type>::push(Type item)
{
    movecount++;
    *top = item;
    top += sizeof(Type);
}

template <typename Type>
Type Stack<typename Type>::pop()
{
    movecount--;
    auto item = *(top - sizeof(Type));     // todo: find solution to not have to subtract
    top -= sizeof(Type);
    memset(top + sizeof(Type), 0, sizeof(Type));
    return item;
}

template <typename Type>
Type Stack<typename Type>::peek()
{
    auto item = *(top - sizeof(Type)); // todo: find solution to not have to subtract
    return item;
}

template <typename Type>
bool Stack<typename Type>::isFull()
{
    return top == stack + sizeof(Type) * maxItems;
}

template <typename Type>
bool Stack<typename Type>::isEmpty()
{
    return top == stack;
}

template <typename Type>
void Stack<typename Type>::print()
{
    for (size_t i = 1; i <= movecount; i++)
        cout << *(top - i* sizeof(Type)) << endl; // todo: find solution to not have to subtract
}

int main()
{
    Stack<char> myStack;
    bool isFull = myStack.isFull();
    bool isEmpty = myStack.isEmpty();
    char aChar = 'a';
    myStack.push(aChar);
    isEmpty = myStack.isEmpty();
    auto val = myStack.peek();
    val = myStack.pop();
    isEmpty = myStack.isEmpty();
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.push(aChar);
    myStack.print();
    isFull = myStack.isFull();

    Stack<float> myStack2;
    isFull = myStack2.isFull();
    isEmpty = myStack2.isEmpty();
    float aFloat = 1.234;
    myStack2.push(aFloat);
    isEmpty = myStack.isEmpty();

    Stack<int> myStack3;
    isFull = myStack3.isFull();
    isEmpty = myStack3.isEmpty();
    int anInt = 1000;
    myStack3.push(anInt);
    isEmpty = myStack3.isEmpty();
}