class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        nums.push_back(0);
        int i=0;
        while(i<nums.size()) {
            if(nums[i]!=i) {
                if(nums[i]==nums[nums[i]]) {
                    i++;
                } else {
                    swap(nums[i], nums[nums[i]]);
                }
            } else {
                i++;
            }
        }
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=i) res.push_back(i);
        }
        return res;
    }
};
