#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int fibonacci_search(int arr[], int arr_size, int find_ele)
{
    int a = 0, b = 1;
    int c;
    int offset = 0;
    while (c <= arr_size)
    {
        c = a + b;

        a = b;
        b = c;
    }
    int i = min(offset + a, arr_size);
    while (arr[i] != find_ele)
    {
        if (arr[i] == find_ele)
            return i;
        else if (arr[i] < find_ele)
        {
            int i = min(offset + a, arr_size);
            offset = c - b;
            c = b;
            b = a;
            a = c - b;
        }

        else if (arr[i] > find_ele)
        {
            c = a;
            b = b - c;
            c = a - b;
        }
    }
}

int main()
{
    int arr[] = {12, 23, 34, 56, 67, 78, 89, 99, 111, 222, 333, 444, 555, 666};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    cout<<fibonacci_search(arr,size,34);
}