#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[k] > arr[j])
                k = j; //selection minimum element position-index
        }
        if (k != i)
            swap(&arr[i], &arr[k]);
    }
    display(arr,size);
}
int main()
{
    int arr[] = {245, 12, 429, 236, 27, 218, 298, 216, 133, 272};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    selection_sort(arr,size);
}