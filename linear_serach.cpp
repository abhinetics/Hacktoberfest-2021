// linera search program
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, target;
    cout <<"Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout <<"Enter the element of array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout <<"Enter the target element : "<< endl;
    cin >> target;
    int k=-1;
    for (int j = 0; j < n; j++){
        if (arr[j] == target){
            k = j;
            break;
        }
    }
    if (k != -1){
        cout << "Index of element is : "<< k;
    }else{
        cout << "target not found";
    }
}