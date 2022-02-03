#include<iostream>
using namespace std;
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void union_(int *arr1,int *arr2,int size1,int size2)
{
    cout<<"inntersection  of two array:";
    int i,j;
    i=j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            cout<<arr2[j]<<" ";
            j++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
    if(i>size1)
    {
        while (j<size2)
        {
            cout<<arr2[j]<<" ";
            j++;
        }
        
    }
    if(j>size2)
    {
        while(i<size1)
        {
            cout<<arr1[i]<<" ";
            i++;
        }
    }
}

void intersection_(int *arr1,int *arr2,int size1,int size2)
{
        cout<<"union of two array:";
    int i,j;
    i=j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            // cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            // cout<<arr2[j]<<" ";
            j++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}
int main()
{
    int arr1[]={12,23,45,47,49,56,58,67,68,69,78,89,97};
    int arr2[]={9,13,23,34,35,45,47,57,67,78,87,89};
    int size1=sizeof(arr2)/sizeof(arr2[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    // display(arr1,arr2,size1,size2);
    union_(arr1,arr2,size1,size2);

cout<<endl;

intersection_(arr1,arr2,size1,size2);

}