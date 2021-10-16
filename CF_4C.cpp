#include<bits/stdc++.h>
#define ll long long
#define mn 10000007
using namespace std;
void cf()
{map<string,int> m;
int t;
cin>>t;
string s;
while(t--)
{
  cin>>s;
  if(m.count(s)==0)
  {cout<<"OK"<<endl;
  m[s]=0;
  }
  else cout<<s<<m[s]<<endl;
  m[s]++;
  }
 
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
      cf();
return 0;
 
}