#include<bits/stdc++.h>
using namespace std;
//function to add two strings
string add(string a, string b){
   string result = "";
   int temp = 0;
   int size_a = a.size() - 1;
   int size_b = b.size() - 1;
   while (size_a >= 0 || size_b >= 0 || temp == 1){
      temp += a[size_a] - '0';
      temp += b[size_b] - '0';
      result = char(temp % 2 + '0') + result;
      temp /= 2;
      size_a--; size_b--;
   }
   return result;
}
int main(){
   string a = "1", b="11";
   cout<<"sum of strings are : "<<add(a, b);
   return 0;
}