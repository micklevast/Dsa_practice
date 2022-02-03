#include <iostream>
void three_flag_method(int *arr, int size);
void swap(int &a, int &b);
using namespace std;
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sort(int *arr, int size)
{
    int c1, c2;
    int c0 = c1 = c2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            c0++;
        if (arr[i] == 1)
            c1++;
        if (arr[i] == 2)
            c2++;
        int k = 0;
        for (int i = 0; i < c0; i++)
        {
            arr[k++] = 0;
        }
        for (int i = 0; i < c1; i++)
        {
            arr[k++] = 1;
        }
        for (int i = 0; i < c2; i++)
        {
            arr[k++] = 2;
        }
    }
    display(arr, size);
}
int main()
{
    int arr[] = {0, 2, 2, 2, 0, 1, 0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    sort(arr, size);
    cout<<"calling function 2-method 2:";
    three_flag_method(arr,size);
}
//method 2

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void three_flag_method(int *arr, int size)
{
    int start = 0, mid = 0, end = size - 1;
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            mid++;
            start++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 2)
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
    display(arr,size);
}