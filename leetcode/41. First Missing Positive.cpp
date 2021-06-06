class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        int i = 0;
        nums.push_back(0);
        while(i<nums.size()) {
            if(nums[i]<0 || nums[i]>=nums.size()) nums[i]=0;
            if(nums[i]==i) {
                i++;
                continue;
            }
            if(nums[nums[i]]>=nums.size()) nums[nums[i]]=0;
            swap(nums[i] , nums[nums[i]]);
            if(nums[i]==nums[nums[i]]) i++;
        }
        i = 1;
        for(;i<nums.size();i++) {
            if(i!=nums[i]) return i;
        }
        return nums.size();
    }
};
