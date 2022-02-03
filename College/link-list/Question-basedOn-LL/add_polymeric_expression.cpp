#include <iostream>
using namespace std;
struct node
{
    int coe;
    int power;
    node *next;
};

void display_polymeric_expression(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->power > 1)
            cout << temp->coe << "x^" << temp->power << " + ";
        if (temp->power == 1)
            cout << temp->coe << "x + ";
        if (temp->power == 0)
            cout << temp->coe;
        temp = temp->next;
    }
    cout << "\n";
}
void substract_poly(node *head1, node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->power == head2->power)
        {
            int total_coe = head1->coe - head2->coe;

            // cout << total_coe << "x^" << head1->power << " + ";
            if (head1->power > 1)
                cout << total_coe << "x^" << head1->power<< " + ";
            if (head1->power == 1)
                cout << total_coe << "x + ";
            if (head1->power == 0)
                cout << total_coe;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
}

int main()
{
    node *a1, *b1, *c1;
    node *a2, *b2, *c2;
    a1 = new node;
    b1 = new node;
    c1 = new node;
    a2 = new node;
    b2 = new node;
    c2 = new node;
    a1->coe = 10;
    a1->power = 2;
    a1->next = b1;
    b1->coe = 8;
    b1->power = 1;
    b1->next = c1;
    c1->coe = 58;
    c1->power = 0;
    c1->next = NULL;
    display_polymeric_expression(a1);

    a2->coe = 9;
    a2->power = 2;
    a2->next = b2;
    b2->coe = 6;
    b2->power = 1;
    b2->next = c2;
    c2->coe = 50;
    c2->power = 0;
    c2->next = NULL;
    display_polymeric_expression(a2);

    
    cout<<"\nsubstration of two polymer:\n";
    substract_poly(a1,a2);
}