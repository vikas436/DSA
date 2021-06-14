class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        if(nums.empty()) return 0;
        stack<int>stk;
        stk.push(0);
        for(int i=1;i<nums.size();i++) {
            if(nums[stk.top()]>nums[i]) {
                stk.push(i);
            }
        }
        int res=0;
        for(int i=nums.size()-1;i>=0;i--) {
            while(!stk.empty() && nums[stk.top()]<=nums[i]) {
                res = max(res,i-stk.top());
                stk.pop();
            }
        }
        return res;
    }
};
