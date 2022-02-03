#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}
void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j = i - 1;

        for (j = i - 1; j >= 0 && cur < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = cur;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {122, 45, 78, 56, 898};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
}