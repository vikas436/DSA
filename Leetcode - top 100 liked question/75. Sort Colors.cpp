class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1) return;
        int l=0,m=0,h=nums.size()-1;
        while(m<=h) {
            switch(nums[m]) {
            case 0: 
                swap(nums[m], nums[l]);
                l++;m++;
                break;
            case 1: 
                m++;
                break;
            case 2: 
                swap(nums[m], nums[h]);
                h--;
                break;
           }
        }
    }
};
