#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(int arr[], int size)
{
    cout << "insertion sort start...\n";
    for (int i = 1; i < size; i++)
    {
        // cout << "outer loop " << i << endl;
        int temp = arr[i];
        int j ;
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {

            // cout << "inner loop " << j << endl;
            arr[j + 1] = arr[j];  
        }
        if (temp != arr[i])
        {
            // cout << "j=" << j << endl;
            arr[j + 1] = temp;
        }
    }
}

int main()
{
    int arr[] = {45, 12, 535, 122, 89, 57, 919, 68};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    insertion_sort(arr, size);
    display(arr, size);
}