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

void val_swaping(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(vector<int> &arr,int top_pos,int size) //passing reference of vector arr so that swaping will aautomatically replicate in final vector also
{
    int largest=top_pos;
    int L_child=largest*2+1;
    int R_child=largest*2+2;
    if(L_child<size && arr[L_child]>arr[largest])
    largest=L_child;

    if(R_child<size && arr[R_child]>arr[largest])
    largest=R_child;

    if(largest!=top_pos)
    {
        cout<<"swaping...\n";
        val_swaping(&arr[largest],&arr[top_pos]);
        cout<<"swaped: "<<arr[largest]<< " and "<<arr[top_pos]<<endl;
        print_arr(arr);
         
        heapify(arr,largest,size);
    }
    else
    return ;


}

void deletion_in_heap(vector<int> arr)
{
    int deleted_ele=arr[0];
    vector<int>::iterator storing_last_element=--(arr.end());
    arr.erase(find(arr.begin(),arr.end(),*storing_last_element));
    
    // replacing last element by top element
    // arr[0]=arr[arr[arr.size()-1]];
    // OR
    arr[0]=*storing_last_element;
    print_arr(arr);

    heapify(arr,0,arr.size());
    cout<<"------------------\n";
    print_arr(arr);



    return;
}

int main()
{
    vector<int> heap_arr{100,80,90,50,40,32,24};
    print_arr(heap_arr);

// deletion of always root element happen
    deletion_in_heap(heap_arr);
}