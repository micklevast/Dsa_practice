#include <iostream>
using namespace std;

struct node
{
    int data;
    node *rand;
    node *next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->rand = NULL;
    }
};

// node *head=NULL;
node *insert_node(int size)
{
    int val;
    cout<<"\nenter head data:";
    cin>>val;

    node *head=new node(val);

    for (int i = 0; i < size; i++)
    {
        cout << "enter your " << i + 1 << " node value:";
        cin >> val;
        node *ptr = new node(val);
        ptr->next=head;
        head=ptr;
    }
    return head;
}
void traverse(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
    cout<<"NULL" <<"\n-----------------------------\n";
}
int main()
{
    cout<<"inserting stack node:";
    node *head=insert_node(5);
    traverse(head);

}