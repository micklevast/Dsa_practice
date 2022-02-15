#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int arr1[] = {12, 45, 23, 12};
    int arr2[] = {5, 23, 5, 89};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    unordered_set<int> s;
    s.insert(arr1,arr1+size1);
    s.insert(arr2,arr2+size2);

    cout<<"union of two array contain "<<s.size()<<" number of element as combined\n";
    for(auto set_ele:s)
    cout<<set_ele<<" ";

}