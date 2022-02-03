#include <iostream>
#include <vector>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void merge(int arr[], int l, int mid, int r)
{
    int ar[12];
    int k = l;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            ar[k++] = arr[j++];
        }
        else
        {
            ar[k++] = arr[i++];
        }
    }
    if (i > mid)
    {
        while (j <= r)
        {
            ar[k++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            ar[k++] = arr[i++];
        }
    }
    int x;
    for (x = l; x <= r; x++)
    {
        arr[x] = ar[x];
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int arr[] = {56, 23, 12, 45, 35, 18, 37, 86, 78, 98};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    merge_sort(arr, 0, size - 1);
    display(arr, size);
}