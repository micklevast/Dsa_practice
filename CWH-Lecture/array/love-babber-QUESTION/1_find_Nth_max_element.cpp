#include <iostream>
#include<algorithm>
using namespace std;
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        // *arr++;
    }
}
int Kth_maximum(int *arr, int size, int Kth_max)
{
    sort(arr,arr+size-1);  //(nlog(n))
    int kth_max=arr[Kth_max-1];
    return kth_max;
}
int main()
{
    int size;
    cout << "enter size of array:";
    cin >> size;
    int *arr = new int(size);
    cout << "enter value of array:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        // *arr++;
    }
    cout << "element of given array:";
    display(arr, size);
    int Kth_max;
    cout << "\nenter which index maximum you want to find:";
    cin >> Kth_max;
    cout << "Kth maximum element is:" << Kth_maximum(arr, size, Kth_max);
}