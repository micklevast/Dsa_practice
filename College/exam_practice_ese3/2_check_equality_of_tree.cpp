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

//ALGORITHM->
// 1. If both trees are empty then return 1.
// 2. Else If both trees are non - empty
//      (a) Check data of the root nodes (tree1->data ==  tree2->data)
//      (b) Check left subtrees recursively  i.e., 
// 	call sameTree( tree1->left_subtree, tree2->left_subtree)
//      (c) Check right subtrees recursively  i.e., 
// 	call sameTree( tree1->right_subtree, tree2->right_subtree)
//      (d) If a,b and c are true then return 1.
// 3  Else return 0 (one is empty and other is not)


/* Given two trees, return true if they are
structurally identical */
int identicalTrees(tnode* a, tnode* b)
{
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
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


    tnode *root1=make_node(56);
    tnode *a1=make_node(23);
    tnode *b1=make_node(89);
    tnode *c1=make_node(34);
    tnode *d1=make_node(190);
    tnode *e1=make_node(78);
    tnode *f1=make_node(688);
    tnode *g1=make_node(43);
    root1->left=a1;
    root1->right=b1;
    a1->left=c1;
    a1->right=d1;
    b1->left=e1;
    b1->right=f1;
    f1->left=g1;

    cout<<"equality:" <<identicalTrees(root,root1);
    
}