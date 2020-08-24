class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        vector<int> vec;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(target-nums[i])!=mp.end()) {
                vec.push_back(mp[target-nums[i]]);
                vec.push_back(i);
                return vec;
            }
            mp[nums[i]]=i;
        }
        return vec;
    }
};
