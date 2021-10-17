#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
int a[t];
for(int i=0;i<t;i++)
{
cin>>a[i];
}int even(0),odd(0),it;
for(int i=0;i<t;i++)
{
if(a[i]%2==0){even++;}
else odd++;}
if(odd>even){
    for(int i=0;i<t;i++)
    {if(a[i]%2==0){cout<<i+1<<endl;break;}
    
}}else 
{for(int i=0;i<t;i++)
    {if(a[i]%2!=0){cout<<i+1<<endl;break;}}}
    return 0;
}