

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&vec, int l, int m, int r) {
    vector<int>left;
    vector<int>right;
    for(int i=l;i<=m;i++) left.push_back(vec[i]);
    for(int i=m+1;i<=r;i++) right.push_back(vec[i]);
    int i=0,j=0,k=l;
    for(;i<left.size() && j<right.size();) {
        if(left[i]<right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
        }
    }
    while(j<right.size()) {
        vec[k++] = right[j++];
    }
    while(i<left.size()) {
        vec[k++] = left[i++];
    }
}
void mergeSort(vector<int>&vec, int l, int r) {
    if(l>=r) {
        return;
    } else {
        int mid = (l+r)/2;
        mergeSort(vec, l, mid);
        mergeSort(vec,mid+1, r);
        merge(vec,l,mid,r);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }  
    mergeSort(vec,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
  return 0;
}

