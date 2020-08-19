// can be optimized the code in better way
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;
        int i=0,j=1;
        while(j<nums.size() && i<nums.size()) {
            if(nums[i]==0 && nums[j]!=0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else {
                if(nums[i]!=0 && nums[j]!=0){
                    i++;
                    j++;
                    continue;
                }
                if(nums[i]==0) j++;
                else if(nums[i]!=0) i++;
            }
        }
    }
};
