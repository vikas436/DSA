void getSize(vector<int>&A, vector<int>&vec, vector<vector<int> > &res ,int l, int k) {
    if(k==0) {
        res.push_back(vec);
        return;
    } else {
        for(int i=l;i<A.size();++i) {
            vec.push_back(A[i]);
            getSize(A,vec,res,i+1,k-1);
            vec.pop_back();
        }
    }
}

bool static isSame(vector<int>A, vector<int>B) {
    int i=0,j=0;
    for(;i<A.size() && j<B.size();) {
        if(A[i]>B[j]) {
            return false;
        } else if(A[i]<B[j]) return true;
        i++;
        j++;
    }
    if(A.size()<B.size()) return true;
    return false;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > res;
    vector<int>vec;
    res.push_back(vec);
    for(int i=0;i<A.size();i++) {
        getSize(A,vec,res,0,i+1);
    }
    sort(res.begin(),res.end(),isSame);
    return res;
}

