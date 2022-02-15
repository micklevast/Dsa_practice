#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print_arr(vector<int> arr)
{
    for(int &x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
// In C++, we have a STL Algorithm find(start, end, item), it accepts three arguments,

// start -> Iterator pointing to the start of a range
// end -> Iterator pointing to the end of a range
// item -> The element that need to be searched in range.
// It iterates over the elements in the range from start to end-1 and looks for the element in range that is equal to item. As soon as it finds the first match, it returns the iterator of that element. If no match is found then it returns the iterator pointing to the end of range.

void val_swaping(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    vector<int> arr{10,9,8,4,5};
    print_arr(arr);
    arr.erase(arr.begin()+2);
    vector<int>::iterator it;

// find(vec.begin(), vec.end(), elem) //these function are from algorithm header file

    it=find(arr.begin(),arr.end(),10);
    arr.erase(it);
    print_arr(arr);

    if(find(arr.begin(),arr.end(),5)!=arr.end())
    cout<<"element 5 is exit\n";
    else
    cout<<"element 5 is not exit\n";

    val_swaping(&arr[0],&arr[1]);
    print_arr(arr);
}