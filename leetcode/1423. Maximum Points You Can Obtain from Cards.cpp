class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        if(k==0) return 0;
        int sum=0, res=0;
        int i=0,j=cp.size()-1;
        while(i<k) {
            sum = sum + cp[i++];
        }
        i--;
        res = max(res ,sum);
        while(i>=0) {
            sum -= cp[i];
            sum += cp[j];
            i--;
            j--;
            res = max(res ,sum);
        }
        return res;
    }
};
