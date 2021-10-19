/*Chef buys a lottery ticket that has a 3 digit code associated with it. He thinks that digit 7 is his lucky digit and brings him good luck.
Chef will win some amount in the lottery if at least one of the digits of the lottery ticket is 7.
Given three digits A, B, and C of the lottery ticket, tell whether Chef wins something or not?*/

#include <iostream>
using namespace std;

int main() 
{
    int t, i;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if (a==7 || b==7 || c==7)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
	return 0;
}
