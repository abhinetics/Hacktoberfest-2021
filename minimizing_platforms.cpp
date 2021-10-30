// Given the arrival and departure times of all trains that reach a railway station, 
//the task is to find the minimum number of platforms required for the railway station so that no train waits. 
#include<bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	sort(arr,arr+n);
	sort(dep,dep+n);
	int i=0,j=0;
	int curr=0, ans=0;
	while(i<n && j<n){
	    if(arr[i]<=dep[j]){
	        curr++;
	        ans=max(ans,curr);
	        i++;
	    }
	    else{
	        curr--;
	        j++;
	    }
	}
	return ans;
}
int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}