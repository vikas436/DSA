class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1), l(n,1);
        if(nums.empty()) return res;
        for(int i=1;i<n;i++) {
            l[i] = l[i-1]*nums[i-1];
        }
        int num = 1;
        for(int i=n-2;i>=0;i--) {
            num*=nums[i+1];
            res[i] = l[i]*num;
        }
        res[n-1]=l[n-1];
        return res;
    }
};
