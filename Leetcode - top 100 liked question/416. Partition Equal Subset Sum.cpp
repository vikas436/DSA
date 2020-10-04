class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), s=0;
        for(int i=0;i<n;i++) s+=nums[i];
        if(s%2==1) return false;
        s = s/2;
        vector<bool>vec(s+1,false);
        vec[0] = true;
        for(int i=0;i<n;i++) {
            for(int j=s;j>=nums[i];j--) {
                vec[j] = vec[j] | vec[j-nums[i]];
            }
        }
        return vec[s];
    }
};
