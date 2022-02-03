#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

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

node *delete_at_begin(node *head)
{
    node *temp = new node;
    temp = head;
    int del_value = temp->data;
    cout << "delete node:" << del_value << endl;
    head = head->next;
    delete temp;
    return head;
}

int delete_at_end(node *head)
{
    node *prev = head;
    node *temp = head->next;
    while (temp->next != NULL)
    {
        prev = prev->next;
        temp = temp->next;
    }
    prev->next = NULL;
    node *del_node = new node;
    del_node = temp;
    int del_value = del_node->data;
    delete del_node;
    return del_value;
}
int delete_given_node(node *head, node *given_node)
{
    node *temp = head;
    // node *temp_next=head->next;
    while (temp->next != given_node)
    {
        temp = temp->next;
        // temp_next=temp_next->next;
    }
    temp->next = given_node->next;
    node *del_node = new node;
    del_node = given_node;
    int del_value = del_node->data;
    delete del_node;
    return del_value;
}
int main()
{
    node *head = new node, *n1, *n2, *n3, *n4;
    // head=NULL;
    n1 = new node;
    n2 = new node;
    n3 = new node;
    n4 = new node;

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
    cout << "Original link-List\n";
    LL_traversal(head);

    cout << "\ndelete node data:" << delete_given_node(head, n3);
    cout << "\nLink-List after deletion The Given Node\n";
    LL_traversal(head);

    head = delete_at_begin(head);
    cout << "\nLink-List after deletion at Begining\n";
    LL_traversal(head);

    cout << "delete node data:" << delete_at_end(head) << endl;
    cout << "\nLink-List after deletion at End\n";
    LL_traversal(head);

}