#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node *head=NULL;
int isFull(node *ptr)
{
    if(ptr==NULL)
    return 1;
    else
    return 0;
}
void push(int val)
{
    node *insert_node=new node;
    if(isFull(insert_node))
    cout<<"stack is overflow\n";
    else
    {
        insert_node->data=val;
        insert_node->next=NULL;
        insert_node->next=head;
        head=insert_node;
    }

}
int isEmpty(node *ptr)
{
    if(ptr==NULL)
    return 1;
    else
    return 0;
}
void display(node* head)
{
    node *ptr=head;
    if(isEmpty(head))
    cout<<"stack is underflow\n";
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL\n";
    }
}
int pop(node **head)
{
    int pop_element=-1;
    if(isEmpty(*head))
    {
        cout<<"stack is underflow\n";
    }
    else
    {
         pop_element=(*head)->data;
        node *del_node=new node;
        del_node=*head;
        (*head)=(*head)->next;
        delete del_node;
    }
        return pop_element;
}
int main()
{
    push(1656);
    push(2656);
    push(3656);
    push(4656);
    push(5656);
    cout<<"after pushing some element in stack:";
    display(head);
    cout<<"pop element 1:"<<pop(&head)<<endl;
    cout<<"pop element 2:"<<pop(&head)<<endl;
    cout<<"pop element 3:"<<pop(&head)<<endl;
    cout<<"pop element 4:"<<pop(&head)<<endl;
    cout<<"pop element 5:"<<pop(&head)<<endl;
    cout<<"pop element 6:"<<pop(&head)<<endl;

    cout<<"-----------------------------------\n";
}