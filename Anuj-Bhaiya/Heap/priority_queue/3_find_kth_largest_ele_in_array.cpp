
// priority queue can have multiple answer for same set of data eg.
// 15 5 10 2 4 3 
// 15 10 5 4 3 2   //it is coompletely in increasing order
// above both are max-heap of same set of data but in different order


// Creating a heap takes O(n) time while inserting into a heap (or priority queue) takes O(log(n)) time
// If you have an empty priority queue to which you want to add n items, one at a time, then the complexity 
// is O(n * log(n)).
#include<iostream>
#include<queue>
using namespace std;
void print_PriorityQueue(priority_queue<int> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop(); //deleting the top/root element
    }
}
int main()
{
    int arr[]={23,45,35,484,67,49,21,68,99};
    int size=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int> pq;
    for(int i=0;i<size;i++)
    {
        pq.push(arr[i]);  //making max-heap using given array
    }

    print_PriorityQueue(pq);
    int kth_pos=4;
    cout<<"\nKth largest element is :";
    // cout<<"size of priority queue:"<<pq.size();
    for(int i=0;i<pq.size();i++)
    {
        if((kth_pos-1)==i)
        {cout<<pq.top()<<endl;
        break;}
        else
        pq.pop();
    }
}