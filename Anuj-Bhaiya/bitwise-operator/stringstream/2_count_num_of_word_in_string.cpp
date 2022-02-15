#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    string str="this is god istruction in this world!";

    stringstream s(str); //breaking sentences into word as token

    string word;
    int count=0;
    while(s>>word)
    {
        count++;
    }
    cout<<"number of words in string :"<<str<<" is:"<<count<<endl;

}