#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *inserting(int val)
{
    node *ptr = new node;

    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}
void traverse_LL(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n--------------------------\n";
}

node *head = new node;
void makinig_LL()
{
    head = inserting(56);
    node *first = inserting(89);
    node *second = inserting(26);
    node *fourth = inserting(98);
    node *fifth = inserting(67);
    head->next = first;
    first->next = second;
    second->next = fourth;
    fourth->next = fifth;
}

node *reverse_LL(node *head) // iterative method
{
    node *ptr = head;
    node *prev = NULL;
    node *next = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;

        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    return prev;
}

void reverse_LL_recursively(node *head)
{
    // NOTE:recursive function first traverse link-list in forword direction then in backword direction so by using these property we can
    // reverese [actually printting from backside not reverse it seem like we have reverseed the given link list]

    node *ptr = head;
    // if(ptr==NULL)
    // return;
    if (ptr->next == NULL)
    {
        head = ptr;
        cout << ptr->data << " ";
        return;
    }

    reverse_LL_recursively(ptr->next);
    cout << ptr->data << " ";
}

node *reverse_LL_recursively2(node *ptr)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->next == NULL)
    {
        // head=ptr;
        return ptr;
    }

    node *node1 = reverse_LL_recursively2(ptr->next);
    (ptr->next)->next = ptr;
    ptr->next = NULL;

    return node1;
}

int main()
{
    makinig_LL();
    traverse_LL(head);

    // head=reverse_LL(head);
    // traverse_LL(head);

    // reverse_LL_recursively(head);

    head = reverse_LL_recursively2(head);
    traverse_LL(head);
}