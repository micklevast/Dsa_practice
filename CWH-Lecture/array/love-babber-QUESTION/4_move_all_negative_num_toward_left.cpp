#include<iostream>
using namespace std;
void move_operation_using_partition(int *arr,int size); //imp
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void move_opeartion(int *arr,int size)
{
    int i=0,j=size-1;
    
    while(i<=j)
    {
        if(arr[i]<0)
        i++;
        else if(arr[i]>0 && arr[j]>0)
        {
            j--;
        }
        else if(arr[i]<0 && arr[j]<0)
        {
            i++;
        }

        else if(arr[i]>0 && arr[j]<0)
        {
            swap(arr[i],arr[j]);
            i++;j--;
        }

    }
    display(arr,size);
}

int main()
{
    int arr[]={-12,89,-63,2,-78,-15,-36,55,-22,6,-6,-1,99,-44};
    int size=sizeof(arr)/sizeof(arr[0]);
    // move_opeartion(arr,size);
    move_operation_using_partition(arr,size);
}

//method2=>like partition process of quick_sort
void move_operation_using_partition(int *arr,int size)
{
    int j=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]<0 )
        {
            if(i!=j)
            swap(arr[i],arr[j]);
        j++;
        }
    }
    display(arr,size);  
}
   