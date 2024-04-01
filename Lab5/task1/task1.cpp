#include <iostream>
using namespace std;

int intersection1(int A[], int B[], int C[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                C[count] = A[i];
                count++;
            }
        }
    }
    return count;
}

int intersection2(int A[], int B[], int C[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (i < n && j < n)
        {
            if (A[i] < B[j])
            {
                i++;
            }
            if (A[i] > B[j])
            {
                j++;
            }
            else
            {
                C[count++] = A[i];
                i++;
                j++;
            }
        }
    }
    return count;
}

int main()
{
    int A[] = {1, 2, 5, 6};
    int B[] = {2, 4, 5, 33};
    int C[10];
    cout << "Intersection between two arrays : " << intersection1(A, B, C, 4) << endl;
    cout << "Intersection two Sorted Arrays : " << intersection2(A, B, C, 4);

    return 0;
}