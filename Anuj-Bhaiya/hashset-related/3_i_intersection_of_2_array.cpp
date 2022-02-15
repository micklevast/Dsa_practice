#include<iostream>

using namespace std;

void intersection(int arr1[],int arr2[],int size1,int size2)
{
    int i=size1,j=size2;
    int small,large;
    if(size1>size2)
    {
        large=size1;
        small=size2;
    }
    else
    {
        large=size2;
        small=size1;
    }

    int arr[5]={};
    int k=0;
    for(int i=0;i<small;i++)
    {
        // cout<<"outer loop\n";
        for(int j=0;j<large;j++)
        {
            // cout<<"inner loop\n";
            if(arr1[i]==arr2[j])
            {
                // cout<<"inner condition\n";
               arr[k++]=arr1[i];
               break;
            }
        }
    }

    cout<<"intersection of given array:\n";
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr1[]={45,12,32,65};
    int arr2[]={12,23,56,45};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    intersection(arr1,arr2,size1,size2);


}