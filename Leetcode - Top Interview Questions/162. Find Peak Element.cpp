class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        stack<int>stk;
        int res = 0;
        for(int i=0;i<nums.size();) {
            if(stk.empty()) {
                stk.push(nums[i++]);
                continue;
            }
            if(stk.top()<nums[i]) {
                stk.push(nums[i]);
                res = i++;
            } else {
                while(!stk.empty())
                    stk.pop();
            }
        }
        return res;
    }
};
