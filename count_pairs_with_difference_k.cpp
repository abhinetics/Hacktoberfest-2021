#include <bits/stdc++.h>
using namespace std;

/*You are given with an array of integers and an integer K. 
You have to find and print the count of all such pairs which have difference K. */

int getPairsWithDifferenceK(int *arr, int n, int k) {
    int ans=0;
    unordered_map<int,int> mp;
    int complement;
 	if(n==1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        complement=arr[i]+k;
        if (mp.find(complement) != mp.end()) {
            ans+=mp[complement];
        }
        if(k!=0)
        {
             complement=arr[i]-k;
             if (mp.find(complement) != mp.end()) {
                ans+=mp[complement];
            }          
        }
        ++mp[arr[i]];
    }
    
	return ans;
}
int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
