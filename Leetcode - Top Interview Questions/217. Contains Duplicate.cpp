class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++) {
            if(st.find(nums[i])!=st.end()) return 1;
            st.insert(nums[i]);
        }
        return 0;
    }
};
