#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;                        // declare varible t
    cin >> t;                     // take value of t from user
    int a[t];                     // declare array of size t with varible name a
    for (int i = 0; i < t; i++){  // take enput of array by user using for loop
        cin >> a[i];
    }
    int even(0), odd(0), it;      // declare and assign value 
    for (int i = 0; i < t; i++){  // run the for loop and check whether number is odd and even
        if (a[i] % 2 == 0){       //if number is even then increase value of even by 1
            even++;
        }                          
        else
            odd++;                 // else increase value of odd by 1
    }
    if (odd > even){                  
        for (int i = 0; i < t; i++){  
            if (a[i] % 2 == 0){
                cout << i + 1 << endl;
                break;
            }
        }
    }
    else{
        for (int i = 0; i < t; i++){
            if (a[i] % 2 != 0){
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}