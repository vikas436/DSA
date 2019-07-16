// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    vector<int>vec(A.size()),arr(A.size());
    vec[A.size()-1]=A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--) {
        if(vec[i+1]<A[i]) {
            vec[i] = A[i];
        } else {
            vec[i]=vec[i+1];
        }
    } 
    arr[0]=A[0];
    for(int i=1;i<A.size();i++) {
        if(arr[i-1]>A[i]) {
            arr[i] = A[i];
        } else {
            arr[i] = arr[i-1];
        }
    }
    
    int i=0,j=0,mx=0;
    while(i<A.size() && j<A.size()) {
        if(arr[i]<=vec[j]) {
            mx = max(j-i, mx);
            j++;
        } else i++;
    }
    return mx;
}
