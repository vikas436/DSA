class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int>vec(nums.size());
        for(int i=0;i<nums.size();i++) {
            if(i<3) {
                vec[i] = nums[i];
                if(i==2) {
                    vec[i] = nums[i]+vec[i-2];
                }
                continue;
            } 
            vec[i] = max(vec[i-2] + nums[i], vec[i-3]+nums[i]);
        }
        return max(vec[vec.size()-1], vec[vec.size()-2]);
    }
};
