#include <iostream>
using namespace std;
struct node
{
    char data;
    node *next;
    node(int val) // maked constructor of this node
    {
        this->data = val;
        this->next = NULL;
    }
};

node *head = new node('A');

node *make_node(int val)
{
    node *x = new node(val);
    return x;
}

void traverse_LL(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
node *mid_node(node *ptr)
{
    node *x = ptr;
    node *y = ptr;
    while (y->next != NULL && y->next->next != NULL)
    {
        x = x->next;
        y = (y->next)->next;
        // cout << "\nx:" << x->data << " y:" << y->data << endl;
    }
    return x;
}

node *reverse(node *ptr)
{
    node *curr = ptr;
    node *prev = NULL;
    node *nexxt = NULL;

    while (curr != NULL)
    {
        nexxt = curr->next;
        curr->next = prev;
        prev = curr;

        curr = nexxt;

    }
    return prev;
}


// comparing each element of main link-list nad reverse-half-linkList
bool compare(node *head, node *reverse_head)
{
    node *x = head;
    node *y = reverse_head;
    while (x != NULL && y != NULL)
    {
        if (x->data != y->data)
            return false;
        x=x->next;
        y=y->next;
    }
    return true;
}

bool check_pelindrome_of_LL(node *head)
{
    node *mid = mid_node(head);
    // cout << "\nmid node:" << mid->data << endl;
    node *reverse_head = reverse(mid->next);
    // traverse_LL(reverse_head);

    bool x = compare(head, reverse_head);
    return x;
}

int main()
{
    // head = make_node('A');
    node *a = make_node('Z');
    node *b = make_node('E');
    node *c = make_node('C');
    node *d = make_node('E');
    node *e = make_node('Z');
    node *f = make_node('A');
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    traverse_LL(head);
    cout<<endl;
    cout <<"pelindrome status:"<< check_pelindrome_of_LL(head);

}