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
int main()
{
    int arr[] = {12, -5, 3, 4,-55,8,-2,-9,111  };
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    int low, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        if (arr[low] < 0)
        {
            low++;
        }
        if (arr[high] > 0)
        {
            high--;
        }
        else if (arr[low] > 0 && arr[high] < 0)
        {
            swap(&arr[low], &arr[high]);
        }
    }
    display(arr, size);
}