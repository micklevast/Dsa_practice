// minimize/maximize height by adding/substrating k into them
#include<iostream>
#include<algorithm>
using namespace std;
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// int Min_H_diff(int arr[],int size)
// {
//     sort(arr[0],arr[size-1]);
//     int min_diff=0;
//     display(arr,size);
//     return min_diff;

// }
int main()
{
    int arr[]={12,3,45,6,17};
    int size=sizeof(arr)/sizeof(arr[0]); 
    // sort(arr[0],arr[size-1]);
    // display(arr,size);
    // min_height_diff=Min_H_diff(arr,size);
}