// preorder traversal
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
void push(int val)
{
    node *insert_node = new node;
    if (isFull(insert_node))
        cout << "stack is overflow\n";
    else
    {
        insert_node->data = val;
        insert_node->next = head;
        //  root->next=insert_node;
        head = insert_node;
    }
}
int isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
int pop(node **head)
{
    int pop_val = -1;
    if (isEmpty(*head))
        cout << "stack is underflow\n";
    else
    {
        pop_val = (*head)->data;
        node *del_node = (*head);
        *head = (*head)->next;
        delete del_node;
    }
    return pop_val;
}
void LL_traversal(node *root)
{
    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

struct tree_node
{
    int data;
    tree_node *left_node;
    tree_node *right_node;
};

tree_node *create(int val)
{
    tree_node *insert_node = new tree_node;
    insert_node->data = val;
    insert_node->left_node = NULL;
    insert_node->right_node = NULL;
    return insert_node;
}
void tree_traversal(tree_node *root)
{
    if(root==NULL)
    return;

    push(root->data);
    tree_node* temp=root;
    
    while(!isEmpty(head))
    {
        int pop_val=pop(&head);
        cout<<pop_val<<" ";
        
        if(root->right_node)
         push(root->left_node->data);

        if(root->left_node)
        push(root->left_node->data);

    }
}

//                 452
//              /      \
//            236       963
//          /    \    /     \
//         23    98  49     93
//        /  \
//       55  0
//
int main()
{

    tree_node *root = create(452);
    tree_node *a = create(236);
    tree_node *b = create(963);
    tree_node *c = create(23);
    tree_node *d = create(98);
    tree_node *e = create(49);
    tree_node *f = create(93);
    // tree_node *g = create(55);
    root->left_node = a;
    root->right_node = b;
    a->left_node = c;
    a->right_node = d;
    b->left_node = e;
    b->right_node = f;
    // c->left_node = g;
    tree_traversal(root);

}