
#include <iostream>
#include <iomanip>
using namespace std;
int partition(int A[], int low, int high);
void quick_sort(int A[], int low, int high);

int main()
{
    int i = 0, n, arr[100];
    cout << "Enter the number of employees:";
    cin >> n;
    cout << endl;
    cout << "Enter the salary of " << n << " employees" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "The array before sorting," << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    cout << endl
         << "Top 5 performers are," << endl;
    int count = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (count == 5)
        {
            break;
        }
        cout << arr[i] << " ";
        count++;
    }
    return 0;
}
void quick_sort(int A[], int low, int high)
{
    int part;
    if (low < high)
    {
        part = partition(A, low, high);
        quick_sort(A, low, part - 1);
        quick_sort(A, part + 1, high);
    }
}
int partition(int A[], int low, int high)
{
    int i, j, temp;
    int pivot = A[low];
    i = low + 1;
    j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
