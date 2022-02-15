#include<iostream>
// #include<priority_queue>
#include<queue>
using namespace std;
void print_min_heap(priority_queue<int,vector<int>,greater<int>> q)
{
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\n-----------------------------\n";
}

void finding_min_cost(int arr[],int size)
{
    priority_queue<int,vector<int>,greater<int>> min_heap_pq;
    for(int i=0;i<size;i++)
    {
        min_heap_pq.push(arr[i]);
    }
    print_min_heap(min_heap_pq);

    int cost_of_rope_one=0,cost_of_rope_two=0;
    int total_cost=0;

    while(!min_heap_pq.empty() && min_heap_pq.size()>1)
    {
        //removing that minimum value rope from min_heap
        cost_of_rope_one=min_heap_pq.top();
        min_heap_pq.pop();

        cost_of_rope_two=min_heap_pq.top();
        min_heap_pq.pop();
        int net_cost_of_these_two_rope=cost_of_rope_one+cost_of_rope_two;

        total_cost+=net_cost_of_these_two_rope; 
    cout<<"minimum cost:"<<total_cost<<endl;

        // add again net price wala rope inside the min_heap
        min_heap_pq.push(net_cost_of_these_two_rope);
        print_min_heap(min_heap_pq);

    }
}

int main()
{
    int cost_of_N_rope[]={ 4, 3, 2, 6 };
    int size=sizeof(cost_of_N_rope)/sizeof(cost_of_N_rope[0]);
    finding_min_cost(cost_of_N_rope,size);
    // 4,5,6 -->5
    // 9 6-->5+9
    // 15 -->5+9+15

}