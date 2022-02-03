#include <iostream>
#include<string>
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
int isOpening(char c)
{
    if(c=='(' || c== '[' || c=='{')
    return 1;
    else
    return 0;
}
int isClosing(char c)
{
    if(c==')' || c==']' || c=='}')
    return 1;
    else
    return 0;
}
int isParenthesisMatched(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    else if(a=='{' && b=='}')
    return 1;
    else if(a=='[' && b==']')
    return 1;
    else
    return 0;
}
int parenthesis_match(string str)
{
    
    for(int i=0;str[i]!='\0';i++)
    {
        if(isOpening(str[i]))
        {
            push(str[i]);
            cout<<str[i];
        }
        else if(isClosing(str[i]))
        {
            cout<<str[i];
            if(isEmpty(s))
            {
                cout<<"excess closing bracket\n";
                return 0;
            }
            else
            {
                char last_bracket=pop();
                if(!isParenthesisMatched(last_bracket,str[i]))
                return 0;
            }
        }
    }
    if(isEmpty(s))
    return 1;
    else
    return 0;
}
int main()
{
    s->top = -1;
    s->size = 20;
    s->str = new char(s->size);
    string str="(9+[6*{5+6}])";
    int check=parenthesis_match(str);
    if(check==1)
    cout<<"\n it is balance parenthesis\n";
    else
    cout<<"\n it is not balance parenthesis\n";

}