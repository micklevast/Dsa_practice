// checking type of variable in cpp
// #include <typeinfo>
// ...
// cout << typeid(variable).name() << endl;

#include <typeinfo>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
//   /*1*/  stringstream str;
//     str << "5";

   /*2*/        stringstream str("5"); //use either of one for to put in data in stream

    int x;
     str >> x;
    cout<<"Converted int value of character 5 :"<<x<<" it's var-type:"<<typeid(x).name()<<endl;

    string s;
    str>>s;
      cout<<"Converted int value of character 5 :"<<x<<" it's var-type:"<<typeid(s).name()<<endl;

      auto xx=s;
      cout<<"type:"<<xx << " =" <<typeid(xx).name()<<endl;
  
    
}