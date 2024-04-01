#include <iostream>
using namespace std;
class Matrix
{
    int *data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            cout << "Error !!";
        }
        else
        {
            this->rows = rows;
            this->cols = cols;
            this->data = new int[cols * rows];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i * cols + j] = 0;
                }
            }
        }
    }
    ~Matrix()
    {
        delete[] data;
    }

    int get(int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
        {
            cout << "Error invalid values ";
        }
        else
        {
            return data[i * cols + j];
        }
    }
    void set(int i, int j, int v)
    {
        if (i < 0 || i > rows || j < 0 || j > cols)
        {
            cout << "Error invalid values ";
        }
        else
        {
            data[i * cols + j] = v;
        }
    }
    void print()
    {
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i * cols + j] << "\t";
            }
            cout << endl;
        }
    }
    void transpose()
    {
        cout << endl;
        for (int j = 0; j < cols; j++)
        {
            for (int i = 0; i < rows; i++)
            {
                cout << data[i * cols + j] << "\t";
            }
            cout << endl;
        }
    }
    void printSubMatrix(int r1, int r2, int c1, int c2)
    {
        if (r1 < r2 && r1 >= 0 && r2 >= 0 && c1 >= 0 && c2 >= 0 && c1 < c2)
        {

            for (int i = r1; i < r2; i++)
            {
                for (int j = c1; j < c2; j++)
                {
                    cout << data[i * cols + j] << "\t";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "ERror invalid value!!" << endl;
        }
    }
    void makeEmpty(int n)
    {
        if (n > 0 && n < cols && n < rows)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    data[i * n + j] = 0;
                }
            }
        }
        else
        {
            cout << "ERRor value is invalid !!" << endl;
        }
    }
    void add(Matrix first, Matrix second)
    {
        if (first.rows == second.rows && first.cols == second.cols)
        {
            this->rows = first.rows;
            this->cols = first.cols;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i * cols + j] = first.data[i * cols + j] + second.data[i * cols + j];
                }
            }
        }
        else
        {
            cout << "There dimensions are not correct!!" << endl;
        }
    }
};
int main()
{
    Matrix m1(4, 5);
    m1.set(0, 1, 5);
    m1.set(1, 1, 55);
    m1.set(2, 1, 5);
    m1.set(1, 5, 4);
    m1.set(4, 1, 3);

    Matrix m2(4, 5);
    m2.set(0, 1, 5);
    m2.set(1, 1, 55);
    m2.set(2, 1, 5);
    m2.set(1, 5, 4);
    m2.set(4, 1, 3);

    cout << "getting function : " << m1.get(1, 1) << endl;

    cout << "Printing " << endl;
    m1.print();
    cout << "Transpose of a matrix " << endl;
    m1.transpose();
    cout << "sub Matrix" << endl;
    m1.printSubMatrix(1, 3, 0, 2);
    cout << "Sum of both the matrix " << endl;
    Matrix m3(3, 3);
    m3.add(m1, m2);
    m3.print();

    // cout << "Making empty function" << endl;
    // m1.makeEmpty(3);
    // m1.print();
    return 0;
}