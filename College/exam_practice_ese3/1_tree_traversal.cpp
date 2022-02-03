#include<iostream>
#include<stack>
using namespace std;
struct tnode{
    int data;
    tnode *left;
    tnode *right;

};

tnode* make_node(int val)
{
    tnode *insert_node=new tnode;
    insert_node->data=val;
    insert_node->left=NULL;
    insert_node->right=NULL;
    return insert_node;
}

void traverse(tnode *root) //inorder traversal with using recurssion
{
    tnode *temp=root;
    if(temp)
    {
        cout<<temp->data<<" ";
        traverse(temp->left);
        traverse(temp->right);
    }
}

void traverse_2(tnode *root) //inorder traversal without using recurssion
{
    // tnode *top=root;
    stack<tnode*> stk;
    tnode *temp=root;
    
        
    while(temp!=NULL || !stk.empty())
    {
        // here curr=temp
                /* Reach the left most Node of the
           curr Node */
        while (temp !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            stk.push(temp);
            temp = temp->left;
        }
        /* Current must be NULL at this point */
        temp = stk.top();
        stk.pop();
 
        cout << temp->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        temp = temp->right;

    }
}

void traverse_3(tnode *root) //clg method->preorder traversal 
{                       //traversing tree without recurssion
    stack<tnode*> stk;
    tnode *temp=root;
    stk.push(temp);
    while(!stk.empty())
    {
        tnode *temp=stk.top();
        cout<<temp->data<<" ";

        stk.pop();
        if(temp->right!=NULL)
        stk.push(temp->right);
        if(temp->left!=NULL)
        stk.push(temp->left);

    }
}

// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}




int main()
{
    tnode *root=make_node(56);
    tnode *a=make_node(23);
    tnode *b=make_node(89);
    tnode *c=make_node(34);
    tnode *d=make_node(190);
    tnode *e=make_node(78);
    tnode *f=make_node(688);
    tnode *g=make_node(43);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    f->left=g;
    traverse(root);
    cout<<endl;

    traverse_2(root);
        cout<<endl;

    traverse_3(root);
}