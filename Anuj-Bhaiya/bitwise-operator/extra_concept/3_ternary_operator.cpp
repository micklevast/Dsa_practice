
#include<iostream>
using namespace std;
int main()
{
// ternary operation return it's if /else condition true value

int a=10;
a+=(a>100)?990:9999990; //a=a+x and x will=>1000 or 10000000 depending upon (a<100)
cout<<"a="<<a<<endl;
a=50;
a-=(a<100)?40:35;  //a=a-x and x will=>40 or 35 depending upon (a<100)
cout<<"a="<<a<<endl;

    // changing x,y,z into zero number using ternary operstor
//     int x=34;
//     int y=0;
//     int z=0;
//     (x=(x>15))?y=--x:z=++x;
//     cout<<"y="<<y<<endl;
//     cout<<"x="<<x<<endl;
//     cout<<"z="<<z<<endl;
//     cout<<(455<555)<<endl;
//     int k=(45<89);
//     cout<<"k="<<k<<endl;

// operation on char
auto q='1'-'0'; //it is auto converted into int for algebric execution
q='0'-'1';
q="111000"-"10";
// auto c='1';
    cout<<"q="<<q<<" sizeof q="<<sizeof(q);

}