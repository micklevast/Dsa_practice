#include <iostream>
#include <string>
using namespace std;
struct node
{

    char data;
    node *next;
};
node *head = NULL;

int isFull(node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}
void push(char val)
{
    node *insert_node = new node;
    if (isFull(insert_node))
        cout << "stack is overflow\n";
    else
    {
        insert_node->data = val;
        insert_node->next = NULL;
        insert_node->next = head;
        head = insert_node;
    }
}
int isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
char pop()
{
    char del_data = '0';
    if (isEmpty(head))
        cout << "stack is overflow\n";
    else
    {
        del_data = head->data;
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    return del_data;
}

int isCLose_braket(char c)
{
    if (c == '(')
        return 1;
    else
        return 0;
}

int parenthesis_match(string str)
{
    int len = str.length();
    int i = 0;
    while (i < len)
    {
        char c = str[i];
        if (isCLose_braket(c))
        {
            push(c);
            cout << c;
        }

        else if (c == ')')
        {
            if (isEmpty(head))
            {
                cout << "extra closing bracket\n";
                return 0;
            }
            char ch = pop();
            cout << c;
        }
        i++;
    }
    if (isEmpty(head))
        return 1;
    else
        return 0;
}

void display()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    string str = ")(((6+9))))";
    cout << "parenthesis matching=" << parenthesis_match(str);
}