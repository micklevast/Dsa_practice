#include <iostream>
using namespace std;
struct node
{

    char data;
    node *next;
};
node *head = NULL;

int isFull(node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}
void push(char val)
{
    node *insert_node = new node;
    if (isFull(insert_node))
        cout << "stack is overflow\n";
    else
    {
        insert_node->data = val;
        insert_node->next = NULL;
        insert_node->next=head;
        head = insert_node;
    }
}
void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data;
        ptr=ptr->next;
    }
    cout<<endl;
}
int main()
{
   
    push(')');
    push('8');
    push('+');
    push('7');
    push('(');
    display();
}