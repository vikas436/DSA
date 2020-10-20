class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int>st;
        for(int i=0;i<nums.size();i++) {
            st.insert(nums[i]);
        }
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            if(st.find(nums[i]-1)==st.end()) {
                int j=i, cnt=0, val=nums[i];
                while(st.find(val)!=st.end()) {
                    cnt++;
                    j++;
                    val++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
