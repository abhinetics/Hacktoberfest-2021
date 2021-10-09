#include <bits/stdc++.h>
using namespace std;

string decimal_to_binary(int n)
{
   string s;
   while(n>0){
       int curr_bit = n&1;
       s+=curr_bit+'0';
       n>>=1;
   }
   reverse(s.begin(),s.end());
   return s;
}
int main()
{   
    int n;
    cout<<"Enter the no. to convert into binary : ";
    cin>>n;
    string bnry = decimal_to_binary(n);
    cout << bnry << "\n";
    return 0;
}