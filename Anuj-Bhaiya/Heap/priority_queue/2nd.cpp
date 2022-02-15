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
    // max-heap creation usiing priority queue
    priority_queue<int> Pq;
    Pq.push(24);
    Pq.push(32);
    Pq.push(80);
    Pq.push(90);
    Pq.push(50);
    Pq.push(40);
    // Pq.push(24);
    print_PriorityQueue(Pq);


}