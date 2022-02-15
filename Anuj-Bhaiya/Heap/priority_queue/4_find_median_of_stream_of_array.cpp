#include<iostream>
#include<queue>
// nserting into max_heap take O(log(n)) as insertion is in heap/complte binary tree
// used time complecity O(n) to stored n element in heap 
using namespace std;

void print_maxHeap_queue(priority_queue<int> q)
{
    cout<<"------------------------\n";
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

void print_minHeap_queue(priority_queue<int,vector<int>, greater<int> > q)
{
    cout<<"------------------------\n";
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

float find_median(int arr[],int size)
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> >min_heap;
       max_heap.push(arr[0]);  //initial add first elemetn into max_heap as to keep max_heap size always greater than min_heap
    for(int i=1;i<size;i++)
    {
        if(arr[i]>max_heap.top() )
        {
            min_heap.push(arr[i]);
        }
        else if(arr[i]<max_heap.top() ) //value is lesser than max_heap ke top se
        {
            max_heap.push(arr[i]);
        }


        if(max_heap.size()>min_heap.size()+1)
        {
            // remove one element from max_heap and insert into min_heap
            int extra_num=max_heap.top();
            max_heap.pop();

            // put extra number into min_heap
            min_heap.push(extra_num);
        }
        else if(min_heap.size()>max_heap.size())
        {
            // remove one elemmt from min_heap and insert into max_heap
            int extra_num=min_heap.top();
            min_heap.pop();

            // add extra number into max_heap
            max_heap.push(extra_num);
        }

    }
    print_maxHeap_queue(max_heap);
    print_minHeap_queue(min_heap);

    if((min_heap.size()+max_heap.size())%2==1)
    return max_heap.top();
    else
    return ((min_heap.top()+max_heap.top())/2);

}
int main()
{
    int arr[]={112,56,89,445,23,35,245,52,164};
    int size=sizeof(arr)/sizeof(arr[0]);
    float median_ans=find_median(arr,size);
    cout<<"Median of given stream of array:"<<median_ans<<endl;
}