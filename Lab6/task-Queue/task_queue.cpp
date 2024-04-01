#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    T *data;
    int front;
    int rear;
    const int MAX_SIZE;

public:
    Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
    {
        front = -1;
        rear = -1;
        data = new T[MAX_SIZE];
    }
    ~Queue()
    {
        delete[] data;
    }
    void enQueue(const T newItem)
    {
        if ((rear + 1) % MAX_SIZE == front)
        {
            cout << "STACK IS FULL \n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            data[rear] = newItem;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            if (rear == front)
            {
                rear = front = -1;
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
        }
    }
    void clear()
    {
        front = rear = -1;
    }
    T getFront() const
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return data[front];
        }
    }
    T getRear() const
    {
        if (rear == -1)
        {
            return -1;
        }
        else
        {
            return data[rear];
        }
    }
    bool isEmpty() const
    {
        if (front == -1 && rear == -1)
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
        if ((rear + 1) % MAX_SIZE == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void showStructure() const
    {
        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << endl;
        }
    }
};
int main()
{
    Queue<float> q1;
    cout << "First two insertions\n";
    q1.enQueue(5.0);
    q1.enQueue(6.5);
    q1.showStructure();

    cout << "After Next two insertions\n";
    q1.enQueue(-3.0);
    q1.enQueue(-8.0);
    q1.enQueue(9.5);

    cout << "Queue is FUll " << q1.isFull() << endl;

  
    q1.showStructure();
  
    cout << "Getting value at rear : " << q1.getRear() << "\nGettig value at front : " << q1.getFront() << endl;
    
    cout << "After using dequeue\n";
    q1.dequeue();
    q1.dequeue();
    q1.showStructure();

    q1.clear();
    cout << "Queue is Empty " << q1.isEmpty() << endl;

    cout << "Getting value at rear : " << q1.getRear() << "\nGettig value at front : " << q1.getFront() << endl;

    return 0;
}