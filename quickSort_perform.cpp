#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int arr[], int first, int last)
{
    int lower = first + 1, upper = last - 1;
    swap(arr[first], arr[(first + last) / 2]);
    int bound = arr[first];

    while (lower <= upper)
    {
        while (bound > arr[lower])
            lower++;
        while (bound < arr[upper])
            upper--;
        if (lower < upper)
            swap(arr[lower++], arr[upper--]);
        else
            lower++;
    }
    swap(arr[upper], arr[first]);
    if (first < upper - 1)
        quickSort(arr, first, upper - 1);
    if (upper + 1 < last)
        quickSort(arr, upper + 1, last);
}

void quickSort1(int a[], int first, int last)
{
    int lower = first + 1, upper = last - 1;
    swap(a[first], a[(first + last) / 2]);
    int bound = a[first];

    while (lower <= upper)
    {
        while (bound > a[lower])
            lower++;
        while (bound < a[upper])
            upper--;
        if (lower < upper)
            swap(a[lower++], a[upper--]);
        else
            lower++;
    }
    swap(a[upper], a[first]);
    if (first < upper - 1)
        quickSort1(a, first, upper - 1);
    if (upper + 1 < last)
        quickSort1(a, upper + 1, last);
}

int main()
{
    int n = 10;
    int array[n] = {53, 81, 22, 74, 45, 35, 13, 16, 91, 60};
    cout << "After perform quick sort: " << endl;
    quickSort(array, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}