class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        int res=0,num,n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[(-1)*(A[i]+B[j])]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                num=C[i]+D[j];
                if(map.count(num)!=0)
                    res+=map[num];
            }
        }
        return res;
    }
};
