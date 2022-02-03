#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    int *arr;
};
stack *s = new stack;
int isFull()
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if (isFull())
        cout << "stack is overeflow\n";
    else
    {
        s->arr[++s->top] = val;
    }
}
int pop()
{
    int poped_val = -1;
    if (isEmpty())
        cout << "stack is underflow\n";
    else
    {
        poped_val = s->arr[s->top--];
    }
    return poped_val;
}
int isOperator(char c)
{
    if (c == '/' || c == '*' || c == '-' || c == '+' || c == '^')
        return 1;
    else
        return 0;
}
int Operator_precedance(char op)
{
    if (op == '(')
        return 4;
    else if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int stack_Top(stack *s)
{
    if (isEmpty())
        return '\0';
    else
        return s->arr[s->top];
}
int prefixEvalute(string str)
{
    int len = str.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (!isOperator(str[i]))
        {
            int x=0;
            if(str[i]>='0' && str[i]<='9')
                x=str[i]-48;
            push(x);
        }
        else if (isOperator(str[i]))
        {
            int operand1 = pop();
            int operand2 = pop();
            int operation = 0;
            switch (str[i])
            {
            case '+':
            {
                operation = operand1 + operand2;
                break;
            }
            case '-':
            {
                operation = operand1 - operand2;
                break;
            }
            case '*':
            {
                operation = operand1 * operand2;
                break;
            }
            case '/':
            {
                operation = operand1 / operand2;
                break;
            }
            case '^':
            {
                operation = operand1 ^ operand2;
                break;
            }
            default:
                break;
            }
            push(operation);
        }
    }
    cout<<"evalution:"<<stack_Top(s)<<endl;
    return (pop());
}

int main()
{
        s->top = -1;
    s->size = 18;
    s->arr = new int(s->size);
    string str="+89";
    cout<<"current string:"<<str<<endl;
    cout<<prefixEvalute(str);
}