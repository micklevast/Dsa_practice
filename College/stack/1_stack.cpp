#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isFull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
void pushing(stack *s, int val)
{
    if (isFull(s))
        cout << "satck is overflow\n";
    else
    {
        s->arr[++s->top] = val;
    }
}
void display(stack *s)
{
    if (isEmpty(s))
        cout << "stack is underflow\n";
    else
    {
        int toop = s->top;
        int i = 0;
        while (i <= toop)
        {
            cout << s->arr[i] << " ";
            i++;
        }
        cout << "\n";
    }
}
int pop(stack **s)
{
    int pop_element = -1;
    if (isEmpty(*s))
        cout << "stack is underflow\n";
    else
    {
        pop_element = (*s)->arr[(*s)->top];
        (*s)->top--;
    }
    return pop_element;
}
int main()
{
    stack *s = new stack;
    s->top = -1;
    s->size = 8;
    s->arr = new int(s->size);
    pushing(s, 1989);
    pushing(s, 2989);
    pushing(s, 3989);
    pushing(s, 4989);
    pushing(s, 5989);
    display(s);
    pushing(s, 6989);
    pushing(s, 7989);
    pushing(s, 8989);pushing(s, 9989);
    display(s);
    cout<<"pop element:"<<pop(&s) <<endl;
    cout<<"after deleting an element the stack:";
    display(s);
    pushing(s, 9989);
     cout<<"after pushing an element the stack:";
    display(s);
}