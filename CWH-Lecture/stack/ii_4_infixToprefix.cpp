#include <iostream>
#include <string>
//correct version for all type of infixTopostfix     
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
    char postfox_exp[20];
    int j = 0;
    int operator_count = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (!isOperator(exp[i]) && exp[i] != '('  && exp[i]!=')') 
        {
            postfox_exp[j++] = exp[i];
        }
        else if (isOperator(exp[i]))
        {
            if (operator_count == 0)
            {
                push(exp[i]);
                operator_count++;
                int op=0;
                cout<<"op:"<<++op<<endl;
            }
            else if (operator_precedance(exp[i]) > operator_precedance(stack_Top(s)))
            {
                push(exp[i]);
            }
            else if (operator_precedance(exp[i]) <= operator_precedance(stack_Top(s)))
            {
                postfox_exp[j++] = pop();
                push(exp[i]);
            }
        }

         else if (exp[i] == ')')
        {
            int close_brack=0;
            // cout<<"close_bract:"<<++close_brack<<endl;
            
            while (stack_Top(s)!='(')
            {
                postfox_exp[j++] = pop();
            }
            cout << "removed open bracket:" << pop() << endl;
        }
    }
    while (!isEmpty(s))
    {
        postfox_exp[j++] = pop();
    }
    for (int k = 0; k < j; k++)
    {
        cout << postfox_exp[k];
    }
}
int main()
{
    s->top = -1;
    s->size = 20;
    s->str = new char(s->size);
    string infix_exp = "(a+b*(c^d-e)^(f+g*h))-i";
    cout << "infix expression:" << infix_exp << endl;
    InfixToPrefix(infix_exp);
}