#include <iostream>
using namespace std;
struct queue
{
    int front, rear;
    int *arr;
    int size;
};
int isEmpty(queue *q)
{
    if (q->front == (-1) || q->front>q->rear)
        return 1;
    else
        return 0;
}
int isFull(queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}
void push(queue *q, int val)
{
    if (isFull(q))
    {
        cout << "queue is  overflow\n";
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->arr[++q->rear] = val;
    }
}

void display(queue *q)
{
    static int count=0;
    cout<<"displaying:"<<++count<<":=>";
    int i = q->front;
    int j = q->rear;
    while (i <= j)
    {
        cout << q->arr[i] << " ";
        i++;
    }
    cout << endl;
}
int pop(queue *q)
{
    int pop_val = -1;
    if (isEmpty(q))
        {cout << "queue is underflow\n";}
    else
    {
        pop_val = q->arr[q->front];
        q->front++;
    }
    return pop_val;
}
int main()
{
    queue *q=new queue;
    q->front = -1;
    q->rear = -1;
    q->size = 5;
    q->arr = new int(q->size);
    push(q, 1623);
    push(q, 2623);
    push(q, 3623);
    push(q, 4623);
    push(q, 5623);
    push(q, 6623);
    //   push(q,623);
    //    push(q,623);
    //     push(q,623);
    display(q);
    cout << "pop value:" << pop(q) << endl;
    cout << "pop value:" << pop(q) << endl;
    display(q);
    push(q, 6623);
    push(q, 7623);
    push(q, 8623);
}