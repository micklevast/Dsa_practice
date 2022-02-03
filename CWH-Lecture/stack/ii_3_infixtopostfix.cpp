#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int top;
    int size;
    char *str;
};
stack *s = new stack;

int isFull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
void push(char val)
{
    if (isFull(s))
    {
        cout << "stack is underflow\n";
    }
    else
    {
        s->str[++s->top] = val;
    }
}

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
char pop()
{
    char remove_char = '0';
    if (isEmpty(s))
        cout << "stack is underflow\n";
    else
    {
        remove_char = s->str[s->top];
        s->top--;
    }
    return remove_char;
}
int isOperator(char c)
{
    if (c == '/' || c == '*' || c == '-' || c == '+' || c == '^')
        return 1;
    else
        return 0;
}
char stack_Top(stack *s)
{
    if (isEmpty(s))
        return '\0';
    else
        return s->str[s->top];
}
int operator_precedance(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    else
        return 0;
}
void InfixToPrefix(string exp)
{
    char str[20];
    int j = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (!isOperator(exp[i]))
        {
            str[j] = exp[i];
            j++;
        }
        else if (isOperator(exp[i]))
        {
            if (isEmpty(s))
            {
                push(exp[i]);
            }

            else if(operator_precedance(exp[i]) > operator_precedance(stack_Top(s)) )
            {
               push(exp[i]); 
            } 
            else //for less and equal precedance ke liye
            {
                str[j++]=pop();
                push(exp[i]);
            }          

        }
    }
    cout<<"top:"<<s->top<<endl;
    while(!isEmpty(s))
    {
        str[j++]=pop();
    }
    // str[j]='\0';
    cout<<"postfix expression:";
    for(int x=0;x<j;x++)
    {
        cout<<str[x];
    }
}
int main()
{
    s->top = -1;
    s->size = 20;
    s->str = new char(s->size);
    string infix_exp = "a+b*c^d-e^f+g*h-i";
    cout << "infix expression:" << infix_exp << endl;
    InfixToPrefix(infix_exp);
}