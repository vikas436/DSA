class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        fun(nums, target, 0, 0, ans);
        return ans;
    }
    void fun(vector<int>& nums, int target, int ind, int sum, int &ans) {
        if(sum==target && ind==nums.size()) {
            ans++;
            return;
        }
        if(nums.size()<=ind) return;
        
        fun(nums, target, ind+1, sum+nums[ind], ans);
        fun(nums, target, ind+1, sum-nums[ind], ans);
    }
};
