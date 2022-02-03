#include<iostream>
using namespace std;

void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void shell_sort(int arr[],int size)
{
    int gap;
    for(gap=size/2;gap>=1;gap=gap/2)
    {
        for(int j=gap;j<size;j++)
        {
            for(int i=j-gap;i>=0;i=i-gap)
            {
                if(arr[i+gap]<arr[i])
                {
                    swap(arr[i+gap],arr[i]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    int arr[]={12,566,4444,32,1558,67,43,88};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    shell_sort(arr,size);
    display(arr,size);

}