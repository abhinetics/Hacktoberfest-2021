#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int n = s.length();
	int dep = 0;
	bool isbal = 1;
	for(auto v:s){ 
		if(v=='(') dep++;
		else dep--;
		if(dep<0) isbal = 0;
	}
	if(dep!=0)isbal = 0;
	if(isbal){
		cout<<"Duplicate Found\n";
	}else{
		cout<<"NO Duplicate Found\n";
	}
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}
