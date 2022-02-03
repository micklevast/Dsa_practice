#include <iostream>
using namespace std;
struct node
{
    int data;
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
void push(int val)  //it follow LIFO
{
    node *insert_node = new node;
    if (isFull(insert_node))
    {
        cout << "Link-list is overflow\n";
    }
    else
    {
        insert_node->data = val;
        // insert_node->next =NULL;  

        insert_node->next=head;
        head = insert_node;
    }
}
void LL_traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
int main()
{
    push(156);
    push(256);
    push(356);
    push(456);
    push(556);
    push(656);
    LL_traversal(head);
    
}