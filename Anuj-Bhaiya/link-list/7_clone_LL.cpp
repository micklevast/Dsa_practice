#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *rand;
    node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->rand=NULL;
    }
};

int traverseNormal(node*head)
{
    int size=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        size++;
        cout<<"data: " <<ptr->data<<" -> ";
        ptr=ptr->next;
    }
    cout<<"NULL\nsize of this Link-List:"<<size <<"\n-------------------------\n";
    return size;
}


int traverse_through_nextPointer(node*head)
{
    int size=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        size++;
        cout<<"data: " <<ptr->data<<"  rand_data:"<<ptr->rand->data<<endl;
        ptr=ptr->next;
    }
    cout<<"NULL\nsize of this Link-List:"<<size <<"\n-------------------------\n";
    return size;
}
node* insert_extra_ele(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        node *temp=ptr->next;

        ptr->next=new node(ptr->data); //inserting duplicate node after that org node itself
        ptr->next->next=temp;

        ptr=temp;

    }
    // int size=traverse_through_nextPointer(head);
    return head;
}

void linking_randPointer(node *head)
{
    node *curr=head;
    // adjust the rand pointers of the
    // newly added nodes
    while (curr)
    {
        // if(curr->next)
        //     curr->next->rand = curr->rand ?
        //                          curr->rand->next : curr->rand;
 
        // move to the next newly added node by
        // skipping an org node
        // curr = curr->next?curr->next->next:curr->next;

        //use below two line OR above code  inside while loop
        curr->next->rand=curr->rand->next;
        curr=curr->next->next;
    }
}

node* duplicate(node *head)
{
    node *org=head;
    node *new_head=org->next;

    int i=0;
    node *temp=new_head;
    while(org!=NULL && new_head!=NULL)
    {
        // org->next=org->next->next;
        org->next =org->next? org->next->next : org->next;

        // new_head->next=new_head->next->next;
        new_head->next = new_head->next?(new_head->next->next):new_head->next;

        org=org->next;
        new_head=new_head->next;
        cout<<"duplicating "<<++i<<"\n";
    }

    // int size=traverse_through_nextPointer(temp);
    return temp;

}

node *head=new node(100);

int main()
{
    node *a=new node(45);
    node *b=new node(89);
    node *c=new node(26);
    node *d=new node(77);

    head->next=a;
    head->rand=b;

    a->next=b;
    a->rand=head;

    b->next=c;
    b->rand=d;

    c->next=d;
    c->rand=b;

    d->next=NULL;
    d->rand=a;

    traverseNormal(head);
    int size=0;
    size=traverse_through_nextPointer(head);
    head=insert_extra_ele(head);
    

    linking_randPointer(head);
    // size=traverse_through_nextPointer(head);

    cout<<"\n----------------------dupllicate of LL------------------------------\n";
    node *new_head_head=duplicate(head);
    size=traverse_through_nextPointer(new_head_head);
}