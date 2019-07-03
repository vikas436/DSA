// https://www.interviewbit.com/problems/combination-sum/

set<vector<int>>st;

void getSum(vector<vector<int> >&res, vector<int>&vec, vector<int>A, int k, int sum, int sum1, int ind) {
    if(sum1>=sum) {
            vector<int> vecTemp = vec;
            sort(vecTemp.begin(),vecTemp.end());
            int sm=0;
            for(int x=0;x<vecTemp.size();x++) sm+=vecTemp[x];
            if(sm==sum){
                if(st.find(vecTemp)==st.end()){
                    res.push_back(vecTemp);
                    st.insert(vecTemp);
                }
                if(sum1!=sum) cout<<"something wrong";
            }
        vecTemp.clear();
        return;
    } else {
        for(int i=ind;i<A.size();i++) {
            vec.push_back(A[i]);
            getSum(res,vec,A,k-1,sum,sum1+A[i],i);
            vec.pop_back();
        }
    }
}

bool static isSame(vector<int>A, vector<int>B) {
    int i=0,j=0;
    for(;i<A.size() && j<B.size();) {
        if(A[i]>B[j]) {
            return false;
        } else if(A[i]<B[j]) {
            return true;
        }
        i++;
        j++;
    }
    return true;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
        vector<vector<int> > res;
        sort(A.begin(),A.end());
        set<int>st1;
        vector<int>temp;
        for(int i=0;i<A.size();i++) st1.insert(A[i]);
        for (auto it=st1.begin(); it != st1.end(); ++it) {
            temp.push_back(*it);
        } 
        A=temp;
        temp.clear();
        sort(A.begin(),A.end());
        long sum=B/A[0];
        vector<int>vec;
        getSum(res,vec,A,sum+1,B,0,0);
        sort(res.begin(),res.end(),isSame);
        st.clear();
        return res;
}
