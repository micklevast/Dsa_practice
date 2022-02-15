#include <iostream>
#include <string>
using namespace std;

// method two only for same sizeof two different binary number

int main()
{
    string bi_num1 = "11";
    string bi_num2 = "11";

    string result = "";

    int size1 = bi_num1.size() - 1;
    int size2 = bi_num2.size() - 1;
    int carry = 0;
    int i = size1, j = size2;
    while (i >= 0 || j >= 0)
    {
        if (bi_num1[i] == '0' && bi_num2[j] == '0')
        {
            if (carry == 1)
            {
                result += '1';
                carry=0;
            }
            else
                result += '0';
        }
        else if (bi_num1[i] == '1' && bi_num2[j] == '0')
        {
            if(carry==1)
            {
                result += '0';               
                carry=1;
            }
            else
            result += '1';
        }
        else if (bi_num1[i] == '0' && bi_num2[j] == '1')
        {
            if(carry==1)
            {
                result += '0';               
                carry=1;
            }
            else
            result += '1';
        }
        else if (bi_num1[i] == '1' && bi_num2[j] == '1')
        {
            if(carry==1)
            {
            result += '1';
            carry = 1;                
            }
            result += '0';
            carry = 1;
        }


        i--;
        j--;
    }
    if(carry==1)
    result += '1';    

    cout<<"result:";
    // cout<<"result size:"<<result.size() <<result[5] <<endl;
    for(int i=result.size()-1;i>=0;i--)
    {
        cout<<result[i];
    }

}