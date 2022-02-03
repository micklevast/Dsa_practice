#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *front=NULL;
node *rear =NULL;
node *head = NULL;

int isFull(node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}
void enqueue(int val)
{
  node *insert_node=new node;
  if(isFull(insert_node)) 
  cout<<"queue is overflow\n";
  else
  {
      insert_node->data=val;
      insert_node->next=NULL;
      if(front==NULL && rear==NULL)
      {
          front=rear=insert_node;
      }
      else
      {
          rear->next=insert_node;
          rear=insert_node;
      }
  }
}
int isEmpty()
{
    if(front==NULL )
    return 1;
    else
    return 0;

}
int dequeue()
{
    int dequeue_val=-1;
    if(isEmpty())
    {cout<<"queue is  underflow\n";}
    else
    {
        node *del_node=front;
        dequeue_val=front->data;
        front=front->next;
        delete del_node;
    }
    return dequeue_val;
}
void display()
{
    node *ptr = front;
    while (ptr != 0)
    {
        cout << ptr->data << "->";
        ptr=ptr->next;
    }
    cout << "NULL\n";
}
int peek()
{
    int peek_val=-1;
    if(isEmpty())
    cout<<"queue is underflow\n";
    else
    {
        peek_val=front->data;
    }
    return peek_val;
}
int main()
{
    enqueue(16);
    enqueue(26);
    enqueue(36);
    enqueue(46);
    enqueue(56);enqueue(66);

    cout<<"peek value:"<<peek()<<endl;
    display();
    cout<<"dequeue val:"<< dequeue()<<endl; 
    cout<<"dequeue val:"<< dequeue()<<endl;
    cout<<"dequeue val:"<< dequeue()<<endl;
    cout<<"dequeue val:"<< dequeue()<<endl;
    cout<<"dequeue val:"<< dequeue()<<endl;
    cout<<"dequeue val:"<< dequeue()<<endl;
    display();

}