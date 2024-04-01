#include <iostream>
#include <string>
using namespace std;

struct Point3D
{
    float x, y, z;
};
class PointList
{
    Point3D *pointArray;
    int maxSize;
    int curSize;
    int cursor;

public:
    PointList(int maxSize)
    {
        this->maxSize = maxSize;
        pointArray = new Point3D[maxSize];
        curSize = 0;
        cursor = -1;
    }

    ~PointList()
    {
        delete[] pointArray;
    }

    bool isEmpty()
    {
        return curSize == 0;
    }
    bool isFull()
    {
        return curSize == maxSize;
    }

    void insert(Point3D newPoint)
    {
        if (!isFull())
        {
            if (isEmpty())
                cursor = 0;
            else
                cursor = curSize;
        }
        pointArray[curSize++] = newPoint;
    }

    void ShowStructure()
    {
        if (isEmpty())
        {
            cout << "Empty List " << endl;
        }
        else
        {
            for (int i = 0; i < curSize; ++i)
            {
                cout << '(' << pointArray[i].x << "," << pointArray[i].y << "," << pointArray[i].z << ")" << endl;
            }
        }
    }

    Point3D getCursor()
    {
        if (!isEmpty())
        {
            if (cursor >= 0 && cursor < curSize)
            {
                return pointArray[cursor];
            }
        }

        Point3D pointerror = {-1, -1, -1};
        cout << "Failed" << endl;

        return pointerror;
    }

    bool gotoBegining()
    {
        if (isEmpty())
        {
            cursor = 0;
            return true;
        }
        return false;
    }

    bool gotoEnd()
    {
        if (!isEmpty())
        {
            cursor = curSize - 1;
        }
        return cursor;
    }
    bool gotoNext()
    {
        if (!isEmpty())
        {
            if (cursor < curSize)
            {
                cursor++;
                return true;
            }
        }
        return false;
    }

    bool gotoPrior()
    {
        if (!isEmpty())
        {
            if (cursor > 0)
            {
                cursor--;
                return true;
            }
        }

        return false;
    }

    void clear()
    {
        curSize = 0;
        cursor = -1;
    }

    bool replace(Point3D newPoint)
    {
        if (!isEmpty() && cursor >= 0 && cursor < curSize)
        {
            pointArray[cursor] = newPoint;
            return true;
        }
        return false;
    }

    void remove()
    {
        if (!isEmpty() && cursor >= 0 && cursor < curSize)
        {
            for (int i = cursor; i < curSize - 1; ++i)
            {
                pointArray[i] = pointArray[i + 1];
            }
            curSize--;

            if (cursor == curSize)
            {
                cursor = 0;
            }
        }
    }
};

int main()
{
    PointList p1(5);

    Point3D p3{2, 8, 5};
    Point3D p4{2, 9, 6};
    Point3D p5{8, 8, 6};

    p1.insert(p3);
    p1.insert(p4);
    p1.insert(p5);
    p1.ShowStructure();

    cout << "Replacing : " << p1.replace(p3) << endl;

    cout << "P1 curSize : " << p1.isEmpty() << endl;
    cout << "P1 maxSize : " << p1.isFull() << endl;

    cout << "P1 go to next : " << p1.gotoNext() << endl;

    cout << "Cursor go to end " << p1.gotoEnd() << endl;

    PointList p2(0);

    cout << "p2 is empty : " << p2.isEmpty() << endl;

    cout << "Cursor go to begining " << p2.gotoBegining() << endl;

    p1.clear();

    cout << "p1 is Empty after clear function : " << p1.isEmpty() << endl;

    return 0;
}