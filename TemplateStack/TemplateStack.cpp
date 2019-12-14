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
    void clear();

private:
    int movecount = 0; // for debugging
    Type* stack;
    Type* top;
};

template <typename Type>
Stack<typename Type>::Stack()
{
    stack = new Type[sizeof(Type) * maxItems]; // allocating memory
    top = stack;
}

template <typename Type>
void Stack<typename Type>::push(Type item)
{
    if (!isFull())
    {
        movecount++;
        *top = item;
        top += sizeof(Type);
    }
    else
    {
        throw std::overflow_error("Pushing not possible: Stack is full!");
    }
}

template <typename Type>
Type Stack<typename Type>::pop()
{
    if (!isEmpty())
    {
        movecount--;
        auto item = *(top - sizeof(Type));
        top -= sizeof(Type);
        memset(top + sizeof(Type), NULL, sizeof(Type));
        return item;
    }
    throw std::underflow_error("Popping not possible: Stack is empty!");
}

template <typename Type>
Type Stack<typename Type>::peek()
{
    if (!isEmpty())
    {
        auto item = *(top - sizeof(Type));
        return item;
    }
    throw std::underflow_error("Peeking not possible: Stack is empty!");
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
        cout << *(top - i* sizeof(Type)) << endl;
}

template <typename Type>
void Stack<typename Type>::clear()
{
    memset(stack, NULL, sizeof(Type) * maxItems);
    top = stack;
}

int main()
{
    Stack<char> myStack;
    bool isFull = myStack.isFull();
    bool isEmpty = myStack.isEmpty();
    // auto var = myStack.peek(); // underflow error
    // auto var = myStack.pop(); // underflow error
    char aChar = 'a';
    myStack.push(aChar);
    isEmpty = myStack.isEmpty();
    auto val = myStack.peek();
    auto val2 = myStack.pop();
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
    // myStack.push(aChar); // overflow error
    myStack.print();
    isFull = myStack.isFull();

    Stack<float> myStack2;
    isFull = myStack2.isFull();
    isEmpty = myStack2.isEmpty();
    float aFloat = 1.234;
    myStack2.push(aFloat);
    isEmpty = myStack2.isEmpty();
    myStack2.print();

    Stack<int> myStack3;
    isFull = myStack3.isFull();
    isEmpty = myStack3.isEmpty();
    int anInt = 1000;
    myStack3.push(anInt);
    myStack3.push(anInt);
    myStack3.push(anInt);
    isEmpty = myStack3.isEmpty();
    myStack3.print();
}