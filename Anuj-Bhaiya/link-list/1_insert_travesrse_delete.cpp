#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *inserting(int val)
{
    node *ptr = new node;

    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}
void traverse_LL(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
node *head=new node;
void makinig_LL()
{
    head = inserting(56);
    node *first = inserting(89);
    node *second=inserting(26);
    node *fourth=inserting(98);
    node *fifth=inserting(67);
    head->next=first;
    first->next=second;
    second->next=fourth;
    fourth->next=fifth;
}
int main()
{
    makinig_LL();
    traverse_LL(head);
}
