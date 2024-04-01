#include <iostream>
#include <math.h>
using namespace std;

class Student
{
    friend class StudentMaxHeap;

private:
    double cgpa;
    int rollno;

public:
    Student(double cgpa, int rollno)
    {
        this->cgpa = cgpa;
        this->rollno = rollno;
    }
    Student() {}
};

class StudentMaxHeap
{
private:
    Student *arr;
    int curSize;
    int maxSize;

public:
    StudentMaxHeap(int size)
    {
        this->curSize = 0;
        this->maxSize = size;
        arr = new Student[size];
    }
    bool insert(double cgpa, int rollno)
    {
        if (maxSize == curSize)
        {
            cout << "Heap is full\n";
        }
        else
        {
            arr[curSize].cgpa = cgpa;
            arr[curSize].rollno = rollno;

            int np = curSize;
            curSize++;

            while (np != 0 && (arr[np].cgpa > arr[(np - 1) / 2].cgpa) || (arr[np].cgpa == arr[(np - 1) / 2].cgpa) && (arr[np].rollno < arr[np - 1 / 2].rollno))
            {
                swap(arr[np], arr[(np - 1) / 2]);
                np = (np - 1) / 2;
            }
        }
        return true;
    }
    void maxHeapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (left < curSize && arr[max].cgpa < arr[left].cgpa || arr[max].cgpa == arr[left].cgpa && arr[max].rollno > arr[left].rollno)
        {
            max = left;
        }
        if (right < curSize && arr[max].cgpa < arr[right].cgpa || arr[max].cgpa == arr[right].cgpa && arr[max].rollno > arr[right].rollno)
        {
            max = right;
        }
        if (max != i)
        {
            swap(arr[max], arr[i]);
            maxHeapify(max);
        }
    }
    bool remove(double &cgpa, int &rollno)
    {
        cgpa = arr[0].cgpa;
        rollno = arr[0].rollno;
        if (curSize > 1)
        {
            arr[0] = arr[curSize - 1];
            curSize--;
            maxHeapify(0);
        }

        return true;
    }

    void displayStudents()
    {
        Student *temp = new Student[curSize];

        for (int i = 0; i < curSize; i++)
        {
            temp[i] = arr[i];
            cout << "Cgpa : " << temp[i].cgpa << " RollNO : " << temp[i].rollno << endl;
        }

        delete[] temp;
    }
    bool isEmpty()
    {
        if (curSize == 0)
        {
            return true;
        }
    }
    bool isFull()
    {
        if (maxSize == curSize)
        {
            return true;
        }
    }
    void levelOrder()
    {
        if (isEmpty())
        {
            cout << "Heap is empty..." << endl;
        }

        for (int level = 0, count = 0, i = 0; i < curSize; i++)
        {
            cout << arr[i].cgpa << " ";
            count++;

            if (count == pow(2, level))
            {
                cout << endl;
                count = 0;
                level++;
            }
        }

        cout << endl;
    }

    ~StudentMaxHeap()
    {
        delete[] arr;
    }
};

void menu()
{
    int choice;
    StudentMaxHeap maxHeap(50);

    do
    {
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int rollNo;
            double cgpa;

            cout << "Enter Roll No: ";
            cin >> rollNo;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            if (maxHeap.insert(cgpa, rollNo))
            {
                cout << "Student Entered...YAAAYYYYYYY.." << endl;
            }
            else
            {
                cout << "Sorryyyy!!!Enternace failed" << endl;
            }
        }
        else if (choice == 2)
        {
            int rollNo;
            double cgpa;
            if (maxHeap.remove(cgpa, rollNo))
            {
                cout << "Student removed: Roll No - " << rollNo << ", CGPA - " << cgpa << endl;
            }
            else
            {
                cout << "Heap is empty...." << endl;
            }
        }
        else if (choice == 3)
            maxHeap.displayStudents();

        else if (choice == 4)
            maxHeap.levelOrder();

        else if (choice == 5)
            cout << "Exiting..." << endl;

        else
            cout << "Invalid choice.\n Please enter a valid option." << endl;

    } while (choice != 5);
}

int main()
{

    menu();

    return 0;
}