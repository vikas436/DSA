// https://www.interviewbit.com/problems/subsets-ii/

set<vector<int>>st;

void getSum(vector<int>&vec, vector<int>A, int l, int k) {
    if(k==0) {
        if(st.find(vec) == st.end()) {
            st.insert(vec);
        }
    } else {
        for(int i=l;i<A.size();i++) {
            vec.push_back(A[i]);
            getSum(vec,A,i+1,k-1);
            vec.pop_back();
        }
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<int>vec;
    for(int i=0;i<A.size();i++) {
        getSum(vec,A,0, i+1);
    }
    vector<vector<int> >resRet;
    resRet.push_back(vec);
    for(auto it=st.begin();it!=st.end();it++) {
        resRet.push_back(*it);
    }
    st.clear();
    return resRet;
}

