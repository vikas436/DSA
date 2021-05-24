class Solution {
public:
    vector<int>sum;
    int getSum(vector<pair<int,int>>&vec) {
        int res=0, s=0;
        for(int i=0;i<vec.size();i++) {
            if(i!=0)
                s = sum[vec[i].second]-sum[vec[i].first-1];
            else s = sum[vec[i].second];
            res = max(res, s);
        }
        return res;
    }
    void rec(vector<int>& nums, int m, vector<pair<int,int>>&vec, int &res, int ind) {
            if(vec.size()>m) {
                return;
            } else if(ind==nums.size()) {
                if(vec.size()==m && vec[vec.size()-1].second==nums.size()-1 && vec[0].first==0) {
                    if(vec.size()>0 && vec[0].first!=0) return;
                    int sum = getSum(vec);
                    res = min(res, sum);
                }
                return;
            }
        for(int i=ind;i<nums.size();i++) {
            vec.push_back(make_pair(ind, i));
            rec(nums, m, vec, res, i+1);
            vec.pop_back();
        }
    }
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty()) return 0;
        sum = nums;
        for(int i=1;i<nums.size();i++) {
            sum[i] = sum[i]+sum[i-1];
        }
        vector<pair<int,int>>vec;
        int res=INT_MAX;
        rec(nums, m, vec, res, 0);
        return res;
    }
};
