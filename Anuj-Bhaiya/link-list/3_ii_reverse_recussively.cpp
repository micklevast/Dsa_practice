#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
node *head = NULL;

node traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << " ->NULL \n--------------------------------\n";
}

void making_LL()
{
    node *temp = NULL;
    int insert_status;
    do
    {
        cout << "enter any non-zero number to insert into link list:";
        cin >> insert_status;

        if (insert_status > 0)
        {
            int insert_val;
            cout << "enter your desire linklist val:";
            cin >> insert_val;

            node *ptr = new node(insert_val);
            if (head == NULL)
            {
                head = ptr;
                temp = head;
            }
            else
            {
                temp->next = ptr;
                temp = ptr;
            }
        }

    } while (insert_status > 0);
}

node* reverse(node *head)
{
    node *ptr=head;
    if(ptr==NULL || ptr->next==NULL)
    return ptr;

    node *node1=reverse(ptr->next);
    ptr->next->next=ptr;
    ptr->next=NULL;

    return node1;
}

int main()
{
    making_LL();
    traversal(head);

    head=reverse(head);
    traversal(head);

    head=reverse(head);
    traversal(head);
}