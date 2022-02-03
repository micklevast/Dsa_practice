#include <iostream>
using namespace std;
struct node
{
    int data;
    int power;
    node *next;
};

node *head = NULL;
void push(int val, int power_)
{
    node *insert_node = new node;
    node *temp;
    insert_node->data = val;
    insert_node->power = power_;
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
void display_polymeric_expression(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->power > 1)
            cout << temp->data << "x^" << temp->power << " + ";
        if (temp->power == 1)
            cout << temp->data << "x + ";
        if (temp->power == 0)
            cout << temp->data;
        temp = temp->next;
    }
    // cout<<"NULL\n";
}
int main()
{
    push(9, 3);
    push(5, 2);
    push(3, 1);
    push(45, 0);
    display_polymeric_expression(head);
}