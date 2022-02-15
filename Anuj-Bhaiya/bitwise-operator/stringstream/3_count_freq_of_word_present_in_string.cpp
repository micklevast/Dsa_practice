#include<iostream>
#include<sstream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string str="workship firstly  of father and mother and father ke father too";

    stringstream s(str); //break down the string into token

    map<string,int> count_freq;

    string word;

    while(s>>word)   //(s) act as cin i.e words coming from stream itself which we have put it in that stingstream
    {
        if(count_freq[word]>0)
        {
            count_freq[word]+=1;
        }
        else
        {
            count_freq[word]=1;
        }
    }

    map<string,int>::iterator mapp;
    for(mapp=count_freq.begin();mapp!=count_freq.end();mapp++)
    {
        cout<<mapp->first<< "   " <<" ->freq:"<<mapp->second<<endl;
    }

}