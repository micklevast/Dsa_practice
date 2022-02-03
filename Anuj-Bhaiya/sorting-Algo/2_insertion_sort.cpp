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

void innsertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int temp=arr[i];
        int j;
        for( j=i-1;j>=0 && temp<arr[j];j--)
        {
            arr[j+1]=arr[j]; //srkao one position aage ki oor
        }
        
        arr[j+1]=temp;
    }
    display(arr,size);
}
int main()
{
    int arr[] = {245, 12, 429, 236, 27, 218, 298, 216, 133, 272};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    innsertion_sort(arr,size);
}