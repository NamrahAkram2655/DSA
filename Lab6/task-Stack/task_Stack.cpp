#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    T *data;
    int top;
    const int MAX_SIZE;

public:
    Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
    {
        top = -1;
        data = new T[MAX_SIZE];
    }
    ~Stack()
    {
        delete[] data;
    }
    void push(const T newitem)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack is Full w cannot insert more elements" << endl;
        }
        else
        {
            top = top + 1;
            *(data + top) = newitem;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }
    void clear()
    {
        top = -1;
    }
    T getTop() const
    {
        return data[top];
    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull() const
    {
        if (top == MAX_SIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void ShowStructure() const
    {
        for (int i = 0; i <= top; i++)
        {
            cout << data[i] << endl;
        }
    }
};
int main()
{

    Stack<float> s1;
    cout << "First two pushes \n";
    s1.push(5.0);
    s1.push(6.5);
    s1.ShowStructure();

    cout << "NEXT TWO PUSHES\n";
    s1.push(-3.0);
    s1.push(-8.0);
    s1.push(-8.0);

    s1.ShowStructure();
    cout << "Stack is full  : " << s1.isFull() << endl;

    cout << "POpping\n";
    s1.pop();
    s1.pop();
    s1.ShowStructure();

    s1.clear();
    cout << "Stack is empty  : " << s1.isEmpty() << endl;

    // cout<<"Considering String \n";
    // Stack<string> s2;
    // s2.push("My ");
    // s2.push("Name is ");
    // s2.push("Namrah Akram ");
    // s2.push("Studying at ");
    // s2.push("PUCIT");

    // s2.ShowStructure();

    // cout << "Stack is full  : " << s1.isFull() << endl;

    return 0;
}