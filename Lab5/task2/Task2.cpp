#include <iostream>
using namespace std;

int findKthSmallest(int A[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
    for (int j = 0; j < n ; j++)
    {
        cout << A[j] << " ";
    }
    cout << endl;
    return A[k];
}

int main()
{
    int A[5] = {1, 2, 6, 0, 55};
    cout << "Smallest Element of array is : " << findKthSmallest(A, 5, 2);
    return 0;
}