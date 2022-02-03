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
int isEmpty(node *head)
{
    if(head==NULL)
    return 1;
    else
    return 0;
}
void push(int val)  //it follow FIFO
{
    node *insert_node = new node;
    node *temp;
    if (isFull(insert_node))
    {
        cout << "Link-list is overflow\n";
    }
    else
    {
        insert_node->data = val;
        insert_node->next =NULL;
        if(head==NULL)  
        {
            temp=head=insert_node; //fixed the head pointer to first node
                              //also initilise the temp node as head node
        }
        else
        {
            temp->next=insert_node;
            temp=insert_node;
        }
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
    cout<<"Link-list empty status before without any element in link-list:"<< isEmpty(head)<<endl;
    
    push(156);
    push(256);
    push(356);
    push(456);
    push(556);
    push(656);
    LL_traversal(head);
    cout<<"Link-list empty status after some element in link-list:"<< isEmpty(head)<<endl;
    
}