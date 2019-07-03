// https://www.interviewbit.com/problems/combination-sum-ii/

int sz;
set<vector<int>>st;
void getSum(vector<vector<int> >&res,vector<int> &vec, vector<int>&A, int l, int sum, int cnt) {
    if(cnt>=sum) {
        vector<int>temp = vec;
        int sm = 0;
        for(int x=0;x<temp.size();x++) sm+=temp[x];
        if(sm==sum) {
            if(st.find(temp)==st.end()) {
                res.push_back(temp);
                st.insert(temp);
            }
        }
        temp.clear();
        return;
    } else {
        for(int i=l;i<A.size();i++) {
            vec.push_back(A[i]);
            getSum(res,vec,A,i+1,sum,cnt+A[i]);
            vec.pop_back();
        }
    }
}
bool static comp(vector<int>A, vector<int>B) {
    int i=0,j=0;
    for(;i<A.size() && j<B.size();) {
        if(A[i]<B[j]) return true;
        else if(B[j]<A[i]) return false;
        i++;
        j++;
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> vec;
    sort(A.begin(), A.end());
    sz=B/A[0];
    getSum(res,vec,A,0,B,0);
    sort(res.begin(),res.end(), comp);
    return res;
}
