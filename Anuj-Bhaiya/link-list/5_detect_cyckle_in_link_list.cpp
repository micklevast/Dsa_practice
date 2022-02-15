#include <iostream>
#include <windows.h>
#include <unordered_map>
#include <map>
#include <iterator>
using namespace std;
struct node
{
    char data;
    node *next;
    node(int val) // maked constructor of this node
    {
        this->data = val;
        this->next = NULL;
    }
};

node *head = new node('W');

node *make_node(int val)
{
    node *x = new node(val);
    return x;
}

void traverse_LL(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        Sleep(100);
    }
}

char detect_starting_of_cycle(node *head)
{
    node *curr = head;
    node *nexxt = head;
    do
    {
        curr = curr->next;
        nexxt = (nexxt->next)->next;
    } while (curr != nexxt && nexxt != NULL); // LINKlIST END NHI HONA CHAHIYE AND jab-tak curr and nexxt mil nhi jaye tab-tak

    // if (nexxt != NULL)
    return curr->data; // as starting of cycle
    // return '0';
}

void print_map(unordered_map<char, int> mp)
{
    // unordered_map<char>::iterator it;
    // for(auto it=mp.begin();it!=mp.end();it++)
    // {
    //     cout<<it->f
    // }
    for (auto it : mp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    cout << "\n--------------------------\n";
}

// #include<map>
char start_of_cycle(node *head)
{
    char returrn = '0';

    node *ptr = head;

    unordered_map<char, int> ump;

    do
    {
        if (ump.find(ptr->data) == ump.end())
        {
            ump.insert({ptr->data, 1});
        }
        else if (ump.find(ptr->data) != ump.end())
        {
            ump.insert({ptr->data, ump[ptr->data] + 1});
            cout << "start/end:" << ptr->data << endl;
            break;
        }

        ptr = ptr->next;
    } while (1);

    return returrn;
}

node *remove_cycle(node *head)
{
    node *ptr = head;
    unordered_map<char, int> ump;

    do
    {
        if (ump.find(ptr->data) == ump.end())
        {
            ump.insert({ptr->data, 1});
            // cout << "element:" << ptr->data << "  ";

            if (ump.find(ptr->next->data) != ump.end())
            { //jaise hi repetition ho jaye then uske just pahle vale ke next ko NULL SET KAR DO
                ptr->next = NULL;
                break;
            }
        }
        ptr = ptr->next;
    } while (1);

    return head;
}

int main()
{
    // head = make_node('A');
    node *a = make_node('A');
    node *b = make_node('B');
    node *c = make_node('C');
    node *d = make_node('D');
    node *e = make_node('E');
    node *f = make_node('F');

    node *aa = make_node('K');
    node *bb = make_node('L');
    node *cc = make_node('M');

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    f->next = aa;
    aa->next = bb;
    bb->next = cc;
    cc->next = c;
    // traverse_LL(head);
    // cout << endl;

    cout<<"start of cycle:" << detect_starting_of_cycle(head);
    cout << endl;

    cout<<"end of cycle:";
    start_of_cycle(head);

    cout<<"\nafter removal of cycle link list is:";
    head = remove_cycle(head);
    traverse_LL(head);
}