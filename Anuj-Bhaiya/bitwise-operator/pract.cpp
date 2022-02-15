#include<iostream>
#include<string>
 #include <sstream>
using namespace std;
int main()
{
    string str="100101";
    int str_size=str.size()-1;
    cout<<"size:"<<str_size<<endl;

    cout<< "str_sub:" << str[str_size-2]-'0'<<endl;
    cout<< "str_add:" << str[str_size-2]-'0'<<endl;

    cout<< "str_sub:" << str[str_size-2]+'0'<<endl;
    cout<< "str_add:" << str[str_size-2]+'0'<<endl;
    cout<<"addd:"<<1+'0'<<endl; 
    cout<<"addd:"<<1+'1'<<endl; 
    int temp=0+'0';
    cout<<"adding:"<<temp<<endl;
    temp+=0+'1';  
    cout<<"adding:"<<temp<<endl;

    string str1="";
    for(int i=0;i<10;i++)
    {
        char c=char(i+48);
        cout<<"C:"<<c<<endl;
        str1+=c;
    }
    cout<<"str1:"<<str1<<endl;


char a = 'A';
 int num1 = (int) a;

char aa = '2';
 int num = aa-48;
 cout<<"num:"<<num<<" "<<"num1:"<<num1<<endl;


// using namespace std;

    stringstream str;
     
    str >>"5";
    int x; 
    str >> x;
    cout<<"Converted value of character 5 :"<<x;


}