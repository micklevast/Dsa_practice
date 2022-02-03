#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    char *arr;
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
char stack_Top(stack *s)
{
    if (isEmpty())
        return '\0';
    else
        return s->arr[s->top];
}

string infixTOpostfix(string str)
{
    string postfix;
    int count_operator = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (!isOperator(str[i])  && str[i] != ')')
        {
            postfix = postfix + str[i];
        }
        else if (isOperator(str[i]))
        {
            if (count_operator == 0 || stack_Top(s)=='(')
            {
                count_operator++;
                push(str[i]);
            }
            else if (isOperator(str[i]) > stack_Top(s))
            {
                push(str[i]);
            }
            else if (isOperator(str[i]) <= stack_Top(s))
            {
              postfix+=pop();
              push(str[i]);
            }
        }
        else if(str[i]==')')
        {
            while(stack_Top(s)!='(')
            {
               postfix+=pop(); 
            }
            char c=pop();
        }
    }
    while(!isEmpty() && stack_Top(s)!='(')
    {
       postfix+=pop(); 
    }
    return postfix;
}

int main()
{
    s->top = -1;
    s->size = 18;
    s->arr = new char(s->size);
    string str="(A+B)*(C*D-E)*F^G";
    cout<<"old expression:"<<str<<endl;
    cout<<"postfix expression:"<<infixTOpostfix(str);
}