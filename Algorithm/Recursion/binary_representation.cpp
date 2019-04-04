#include <bits/stdc++.h>
using namespace std;

void binary(int arr[], int n,int m) {
    if(n==m) {
        for(int i=0;i<m;i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    arr[n]=0;
    binary(arr,n+1,m);
    arr[n]=1;
    binary(arr, n+1,m);
}
int main() {
    int n;
    cin>>n;
    int arr[n]={0};
    binary(arr,0,n);
    return 0;
}
