class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int>lis(nums.size(),1);
        int res = 1;
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i]) {
                    lis[i] = max(lis[i], lis[j]+1);
                    res = max(res, lis[i]);
                }
            }
        }
        return res;
    }
};
