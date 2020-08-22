class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int res=0,sum=0, isMax=nums[0];
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum<0) {
                sum=0;
            } else {
                res = max(res, sum);
            }
            if(isMax<nums[i]) isMax=nums[i];
        }
        if(isMax<0) return isMax;
        return res;
    }
};
