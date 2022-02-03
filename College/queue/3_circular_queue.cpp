#include <iostream>
#include <windows.h>
// #include<ios>
// #include<time.h>
// #include<Windows
using namespace std;
class queue
{
public:
    int data;
    queue *next;
    // int  size;
} * q;

queue *head = NULL;
queue *front = 0;
queue *rear = 0;
int isFull(queue *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    queue *insert_node = new queue;
    if (isFull(insert_node))
    {
        cout << "queue is overflow\n";
    }
    else
    {
        insert_node->data = val;
        insert_node->next = NULL;
        if (front == 0 && rear == 0)
        {
            front = rear = insert_node;
        }
        else
        {
            rear->next = insert_node;
            rear = insert_node;
            rear->next=front;
        }
    }

}
int isEmpty()
{
    if(front==NULL && rear==NULL)
    return 1;
    else
    return 0;
}
int dequeue()
{
    int del_data=-1;
    if(isEmpty())
    {
        cout<<"queue is underflow\n";
    }
    else
    {
        queue *del_ptr=front;
         del_data=del_ptr->data;
        front=front->next;
        delete del_ptr;
    }
    return del_data;
}

void display()
{
    queue *ptr = front;
    int size=8;
    int i=0;
    while (i<size)
    {i++;
        cout << ptr->data << "->";
        Sleep(1000);
        ptr = ptr->next; 
    }
    cout << "NULL\n";
}

int main()
{
    enqueue(1898);
    enqueue(2898);
    enqueue(3898);
    enqueue(4898);
    enqueue(5898);
    enqueue(6898);
    enqueue(7898);
    enqueue(8898);
    display();
    cout<<"dequeue val:" <<dequeue()<<endl;
    cout<<"dequeue val:" <<dequeue()<<endl;
    display();
}