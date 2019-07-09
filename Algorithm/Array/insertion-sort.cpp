
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&vec) {
    for(int i=1;i<vec.size();i++) {
        int j=i-1;
        int temp = vec[i];
        while(temp<vec[j] && j>=0) {
            vec[j+1] = vec[j];
            j--;
        }
        if(j!=i-1)  
        vec[j+1] = temp; 
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }  
    insertionSort(vec);
    for(int i=0;i<n;i++) {
        cout<<vec[i]<<" ";
    } 
  return 0;
}

