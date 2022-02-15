#include<list>
#include<iostream>
using namespace std;

void traverse_LL(list<int> ll)
{
    for(auto it=ll.begin();it!=ll.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n---------------------\n";
}

int main()
{
    list<int> ll,ll2;
    ll.push_back(56);
    ll.push_back(89);
    ll.push_back(69);
    ll.push_back(44);
    ll.push_back(88);
    traverse_LL(ll);

    ll2.push_front(56);
    ll2.push_front(89);
    ll2.push_front(69);
    ll2.push_front(44);
    ll2.push_front(88);
    traverse_LL(ll2);

    // reverse the Link-list
    ll2.reverse();
    traverse_LL(ll2);

    // sorting
    ll2.sort();
    traverse_LL(ll2);
}