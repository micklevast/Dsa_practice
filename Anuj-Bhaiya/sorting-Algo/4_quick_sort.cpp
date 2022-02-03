#include <iostream>
using namespace std;
int partion_in_array(int arr[],  int left, int right);
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
void quick_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int k=partion_in_array(arr, l, r);
        // int mid=(l+r)/2;
        quick_sort(arr,l,k-1);
        quick_sort(arr,k+1,r);
    }
   
}
int partion_in_array(int arr[],  int left, int right)
{
    int i = left, j = right;
    // int mid=(i+j)/2;
    int temp = arr[left];
    while (i < j)
    {
        while (arr[i] <= temp)
            i++;
        while (arr[j] > temp)
            j--;
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[left]);
    return j;
}
int main()
{
    int arr[] = {245, 12, 429, 236, 27, 218, 298, 216, 133, 272};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    quick_sort(arr,0,size-1);
     display(arr,size);
}