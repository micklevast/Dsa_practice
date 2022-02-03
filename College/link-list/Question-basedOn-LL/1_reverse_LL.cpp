#include <iostream>
using namespace std;
// node* reverse_recursive(node *head);
struct node
{

    int data;
    node *next;
};

node *head = NULL;
void push(int val)
{
    node *insert_node = new node;
    node *temp;
    insert_node->data = val;
    insert_node->next = NULL;
    if (head == NULL)
    {
        temp = head = insert_node;
    }
    else
    {
        temp->next = insert_node;
        temp = insert_node;
    }
}
void traversal(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void iterative_reverse_LL(node **head)
{
    node *curr=*head;
    node *prev=NULL;
    node *nexxt=NULL;
    while(curr!=NULL)
    {
        nexxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nexxt;
    }
    *head=prev;
    // return prev;
}

node* reverse_recursive(node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    node *new_head=reverse_recursive(head->next);
    // head->next->next=head;
    node *q=head->next;
    q->next=head;
    head->next=NULL;
    return new_head;
}
int main()
{
    push(56);
    push(89);
    push(76);
    push(19);
    traversal(head);
    // iterative_reverse_LL(&head);
    // traversal(head);
   
    head=reverse_recursive(head);
    traversal(head);
}

