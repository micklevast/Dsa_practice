#include <iostream>
#include <unordered_set>
using namespace std;

void printSet(unordered_set<int> s)
{
    for(auto it:s)
    cout<<it<<" ";
    cout<<endl;
}


void intersection(int arr1[], int arr2[], int s1, int s2)
{
    unordered_set<int> sett;
    sett.insert(arr1, arr1 + s1);

    int arr[10] = {};
    int k = 0;
    for (int i = 0; i < s2; i++)
    {
       
        if (sett.count(arr2[i]))
        {
            arr[k++] = arr2[i];
            sett.erase(arr2[i]);
        }
    }

    cout<<"intersection of given array:";
    for(int l=0;l<k;l++)
    {
        cout<<arr[l]<<" ";
    }
    cout<<endl;

}

int main()
{
    int arr1[] = {45, 12, 32, 65};
    int arr2[] = {12, 23, 56, 45,89,23,65};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    intersection(arr1, arr2, size1, size2);
}