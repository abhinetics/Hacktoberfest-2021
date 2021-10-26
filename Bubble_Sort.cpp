#include <iostream>
using namespace std;


void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}


int bubble(int arr[] , int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }

    }
}



int main()
{
    int arr[]={5,2,6,8,1};
    bubble(arr,5);

    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}
