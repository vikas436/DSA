class Solution {
public:
    int min(int a, int b) {
        if(a<b) return a;
        return b;
    }
    bool canJump(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind == nums.size()-1) return true;
        if(dp[ind]!=-1) return dp[ind];
        int end = min(ind + nums[ind], nums.size()-1);
        for(int i=end;i>=ind+1; i--) {
            if(canJump(nums, i, dp)) {
                dp[i] = 1;
                return true;
            }
        }
        dp[ind] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
        // vector<int>dp(nums.size(), -1);
        // return canJump(nums, 0, dp);
    }
};
