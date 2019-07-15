// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
vector<int> getsolve(int A) {
    vector<int>vec,res;
    if(A==0) {
        return res;
    }
    vec.push_back(1);
    for(int i=1;i<A;i++) {
        res = vec;
        vec.clear();
        for(int j=0;j<=res.size();j++) {
            if(j==0 || j==res.size()) {
              vec.push_back(1);
            } else {
                vec.push_back(res[j-1]+res[j]);
            }
        }
    }
    res = vec;
    return res;
}
vector<int> Solution::getRow(int A) {
    return getsolve(A+1);
}

