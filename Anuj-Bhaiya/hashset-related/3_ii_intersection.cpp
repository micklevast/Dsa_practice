#include <iostream>
#include <unordered_set>
using namespace std;

void intersection(int arr1[], int arr2[], int s1, int s2)
{
    unordered_set<int> sett;
    sett.insert(arr1, arr1 + s1);
    int arr[10] = {};
    int k = 0;
    for (int i = 0; i < s2; i++)
    {
        //  If the specified element is found, an iterator to the element is returned; otherwise, an iterator to the end of the container is returned.
        if (sett.find(arr2[i]) != sett.end())
        {
            arr[k++] = arr2[i];
            sett.erase(arr2[i]);
            // cout<<arr2[i]<<"  ";
        }
    }
    cout<<"intersection of given array:\n";
    for(int l=0;l<k;l++)
    {
        cout<<arr[l]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr1[] = {45, 12, 32, 65};
    int arr2[] = {12, 23, 56, 45,65,89,45};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    intersection(arr1, arr2, size1, size2);
}