#include <queue>
#include <iostream>

using namespace std;


struct comparator
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

// Note:
// Instead of defining an explicit comparator structure, one can also use greater<data_type>. This is defined in the
// functional package.

int main()
{
    priority_queue<int, vector<int>, comparator> minHeap;
    // OR
    // priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(24);
    minHeap.push(40);
    minHeap.push(32);
    minHeap.push(50);
    minHeap.push(90);
    minHeap.push(80);

    while (!minHeap.empty())
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }

    return 0;
}