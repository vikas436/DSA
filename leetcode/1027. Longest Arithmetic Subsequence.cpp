class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        vector<unordered_map<int, int>>vec(nums.size());
        int res = 2;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                int diff = nums[j]-nums[i];
                if(vec[i].find(diff)!=vec[i].end()) {
                    vec[j][diff] = vec[i][diff] + 1;
                } else {
                    vec[j][diff]=2;
                }
                res = max(res, vec[j][diff]);
            }
        }
        return res;
    }
};
