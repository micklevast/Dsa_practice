#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    // int total_distinct_ele_in_given_arr=0;
    unordered_set<int> hash_element;
    int arr[]={45,12,32,12,12,45,56,32,23,32,89,78,58};
    int size=sizeof(arr)/sizeof(arr[0]);
hash_element.insert(arr,arr+size);
    for(auto it:hash_element)
    cout<<"distinct element:"<<it<<endl;

cout<<"total_distinct_ele_in_given_arr:"<<hash_element.size()<<endl;

}