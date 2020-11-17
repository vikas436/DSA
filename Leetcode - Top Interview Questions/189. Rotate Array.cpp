class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0 || nums.size()<=1) return ;
        k = k%nums.size();
        int l=0,m=nums.size()-k-1,r=nums.size()-1,m1=nums.size()-k;
        while(l<m) {
            swap(nums[l++], nums[m--]);
        }
        while(r>m1) {
            swap(nums[r--], nums[m1++]);
        }
        l = 0;
        r = nums.size()-1;
        while(l<r) {
            swap(nums[l++], nums[r--]);
        }
    }
};

