class Solution {
public:
    int validate(vector<int> nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]>0 || nums[i+1]>0) return 1;
            if(nums[i]<0 && nums[i+1]<0) return 1;
        }
        if(nums.size()==1) return nums[nums.size()-1]>0;
        return 0;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1 && nums[0]<0) return nums[0];
        int val = validate(nums);
        int flg=0,res=INT_MIN, mx=1,mn=1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                mx = mx*nums[i];
                mn = min(1, mn*nums[i]);
            } else if(nums[i]==0) {
                mx=1;
                mn=1;
                flg=1;
            } else {
                int m = mx;
                mx = max(1, mn*nums[i]);
                mn = m*nums[i];
            }
            res = max(res, max(mx,mn));
        }
        if(flg==1 && res<0) return 0;
        if(val==0) return 0;
        return res;
    }
};
