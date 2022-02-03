#include<iostream>
#include<string>
using namespace std;
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void backTracking_permutation(string str,int start,int end)
{
    if(left==right)
    {
        cout<<"str:"<<str<<endl;
    }
    else{
        for(int i=start;i<=end;i++)
        {
            swap(str[start],str[i]);
            backTracking_permutation(str,start+1,end);
             swap(str[start],str[i]);
        }
    }
}
int main()
{
    string str="HAEMSRT";
    int len=sizeof(str);
    backTracking_permutation(str,0,len-1);

}