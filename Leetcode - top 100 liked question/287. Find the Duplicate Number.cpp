class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        nums.push_back(0);
        int i=0;
        while(i<nums.size()) {
            if(nums[i]==nums[nums[i]]) return nums[i];
            if(nums[i]!=i) {
                swap(nums[i], nums[nums[i]]);
            } else i++;
        }
        return -1;
    }
};
