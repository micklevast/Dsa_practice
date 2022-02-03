#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

int isFull(node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}
int isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
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
node *insert_1_at_begin(node *head, int val)
{
    node *new_node = new node;
    if (isFull(new_node))
        cout << "LL is overflow\n";
    else
    {
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }
    return head;
}
void insert_2_at_end(node *head, int val)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *new_node = new node;
    new_node->data = val;
    new_node->next = NULL;
    temp->next = new_node;
}

node *insert_3_at_given_index(node *head, int index, int val)
{
    node *new_node = new node;
    node *temp = head;
    if (index == 0)
    {
        new_node->data = val; //insertion at begining
        new_node->next = NULL;

        new_node->next = head;
        head = new_node;
    }
    else
    {
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp != NULL)
        {
            new_node->data = val; //insertion after anywhere head node
            new_node->next = NULL;
            new_node->next = temp->next;
            temp->next = new_node;
        }
        else
        {       //try to insert after last node
            cout << "insertion failed! please give suitable index .\n";
        }
    }
    return head;
}

void insert_4_after_given_node(node *given_node,int val)
{
    node *new_node=new node;
    new_node->data=val;
    new_node->next=given_node->next;
    given_node->next=new_node;
}


int main()
{
    node *head = new node, *n1, *n2, *n3, *n4;
    // head=NULL;
    n1 = new node;
    n2 = new node;
    n3 = new node;
    n4 = new node;
    cout << "is Empty:" << isEmpty(head) << endl;
    cout << "is Full:" << isFull(n1) << endl;
    head->data = 45;
    head->next = n1;
    n1->data = 989;
    n1->next = n2;
    n2->data = 56;
    n2->next = n3;
    n3->data = 821;
    n3->next = n4;
    n4->data = 456;
    n4->next = NULL;
    cout<<"original Link-List:\n";
    LL_traversal(head);

    head=insert_1_at_begin(head,888);
    cout<<"\nlink-list Insertion at Begining:\n";
    LL_traversal(head);

    insert_2_at_end(head,1000);
       cout<<"\nlink-list Insertion at End:\n";
    LL_traversal(head);

    head = insert_3_at_given_index(head, 7, 555);
       cout<<"\nlink-list Insertion at GIven Index:\n";
    LL_traversal(head);

    insert_4_after_given_node(n3,777);
       cout<<"\nlink-list Insertion After given Node:\n";
    LL_traversal(head);


}
