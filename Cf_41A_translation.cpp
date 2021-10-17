#include<bits/stdc++.h>
using namespace std;
int main()
{string s1,s2;
cin>>s1>>s2;
int n=s1.length();
int count=0;
for(int i=0;i<s1.length();i++)
{if(s1[i]==s2[n-1-i])
{count++;}
 
}if(count==n)
cout<<"YES";
else cout<<"NO";
    return 0;
 
}