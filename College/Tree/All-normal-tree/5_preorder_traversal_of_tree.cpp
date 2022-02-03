#include <iostream>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
};
tree *create_node(int val)
{
    tree *insert_node = new tree;
    insert_node->data = val;
    insert_node->left = NULL;
    insert_node->right = NULL;
    return insert_node;
}
void preorder_traversal(tree *root)
{
    tree *temp = root;
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}
//                 5000
//              /      \
//            562       236
//          /    \    /     \
//         896   745  358     496
//        /  \
//       55  0
//
struct node
{
    tree data;
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
    if (head == NULL)
        return 1;
    else
        return 0;
}
void push(tree val)
{
    node *insert_node = new node;
    if (isFull(insert_node))
        cout << "stack is overflow\n";
    else
    {
        insert_node->data = val;
        insert_node->next = head;
        head = insert_node;
    }
}
tree stack_top(node *head)
{
    return head->data;
}
void pop(node **head)
{
    // tree  poped_val=NULL;
    if (isEmpty(*head))
        cout << "stack is  underflow\n";
    else
    {
        //  poped_val=(*head)->data;
        // cout<<"poped val:" <<poped_val.data<<endl;
        (*head) = (*head)->next;
    }
}
void preorder_non_recursive_traversal(tree *root)
{
    tree *temp = root;
    push(*temp);
    while (!isEmpty(head))
    {
        tree top = stack_top(head);
        cout << top.data << " ";
        // tree *tpp=&top;
        // pop(&head);
        // if(tpp->left!=NULL)
        // push(*tpp->right);
        // if(tpp->left)
        // push(*tpp->left);

        pop(&head); //use these set of code OR use above code for same purpose
        if (top.right != NULL)
            push(*top.right);
        if (top.left != NULL)
            push(*top.left);
    }
}
//                5000
//              /      \
//            562       236
//          /    \    /     \
//         896   745  358     496
//        /  \   /  \ / \    /  \
//       0   0  0   0 0 0   0    0
void inorder_traversal(tree *root)
{
    tree *curr = root;
    push(*curr);
    while (!isEmpty(head) || curr != NULL)
    {
        cout << "outer loop  ";

        while (((*curr).left) != NULL)
        {
            cout << "inner loop\n";
            cout << "curr data:" << curr->data << endl;
            curr = curr->left;
            if (curr != NULL)
                push(*curr);
           
        }
        *curr = stack_top(head);
        cout << "here";
        pop(&head);
        cout << curr->data << " ";
        curr = curr->right;
    }
}
int main()
{
    tree *root = create_node(5000);
    tree *a = create_node(562);
    tree *b = create_node(236);
    tree *c = create_node(896);
    tree *d = create_node(745);
    tree *e = create_node(358);
    tree *f = create_node(496);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    // preorder_traversal(root);
    // cout << endl
    //      << endl;
    // preorder_non_recursive_traversal(root);
    inorder_traversal(root);
}