#include <iostream>
using namespace std;
//not totally correct work on it
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
void push(char val)
{

    if (isFull())
        cout << "stack is overflow\n";
    else
    {
        s->arr[++s->top] = val;
    }
}
int isEmpty()
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
char pop()
{
    char poped_val = '\0';
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
string infix_to_profix(string exp)
{
    char postfix_exp[20];
    int j = 0;
    int count_operator = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(') //pushing first opening bracket
        {
            push(exp[i]);
            int b = 0;
            cout << "b:" << b++ << endl;
        }
        else if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {

            {
                postfix_exp[j++] = exp[i];
                static int a = 0;
                cout << "a:" << a++ << endl;
            }
        }
        else if (isOperator(exp[i]))
        {
            if (count_operator == 0) //pushing first operator
            {
                push(exp[i]);
                count_operator++;
                static int c = 0;
                cout << "c:" << c++ << endl;
            }
            else if (Operator_precedance(exp[i]) > Operator_precedance(stack_Top(s))) //for more  precedance from s->top
            {
                push(exp[i]);
                int d = 0;
                cout << "d:" << d++ << endl;
            }
            else if (Operator_precedance(exp[i]) <= Operator_precedance(stack_Top(s))) //for 1)equal and less precedance from s->top
            {
                postfix_exp[j++] = pop();
                push(exp[i]);
                int e = 0;
                cout << "e:" << e++ << endl;
            }
        }
        else if (exp[i] == ')')
        {
            while (stack_Top(s) != '(')
            {
                int i = 0;
                cout << "i:" << i++ << endl;
                postfix_exp[j++] = pop();
            }
            char c = pop(); //pop extra '(' from stack
        }
    }
    while (!isEmpty() && (stack_Top(s) != '('))
    {
        postfix_exp[j++] = pop();
        int g = 0;
        cout << "g:" << g++ << endl;
    }
    for (int x = 0; x < j; x++)
    {
        cout << postfix_exp[x];
    }
    postfix_exp[j] = '\0';
    cout << endl;
    return postfix_exp;
}
int main()
{
    s->top = -1;
    s->size = 10;
    s->arr = new char(s->size);
    string str = "(a+b)";
    cout << infix_to_profix(str);
}