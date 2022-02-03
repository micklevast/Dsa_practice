#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int front, rear;
    int *arr;
} * q;

int isEmpty()
{
    if(q->front<0 || q->front>q->rear)
    return 1;
    else
    return 0;
}
int dequeue()
{
    int dequeue_val=-1;
    if(isEmpty())
    cout<<"queue is underflow\n";
    else
    {
        dequeue_val=q->arr[q->front++];
    }
    return dequeue_val;
}
int main()
{
    q = new queue;
    q->front=q->rear=-1;
    q->size=6;
    q->arr=new int(q->size);
    q->arr[++q->rear]=1326;
    q->front++;
    q->arr[++q->rear]=2326;
    q->arr[++q->rear]=3326;
    q->arr[++q->rear]=4326;
    q->arr[++q->rear]=5326;
    q->arr[++q->rear]=6326;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;
    cout<<"dequeue value:"<<dequeue()<<endl;

}