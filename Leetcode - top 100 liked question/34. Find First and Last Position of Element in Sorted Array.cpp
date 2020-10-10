// 34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    int lBinary(vector<int>nums, int l, int r, int k) {
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(mid==0 && nums[mid]==k) return mid;
        if(mid>0 && nums[mid-1]<k && nums[mid]==k) return mid;
        if(nums[mid]>=k) {
            return lBinary(nums, l, mid-1, k);
        } else {
            return lBinary(nums, mid+1, r, k);
        }
    }
    
    int rBinary(vector<int>nums, int l, int r, int k) {
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(mid==nums.size()-1 && nums[mid]==k) return mid;
        if(nums.size()>mid+1 && nums[mid]==k && nums[mid+1]>k) return mid;
        if(nums[mid]>k) {
            return rBinary(nums, l, mid-1, k);
        } else {
            return rBinary(nums, mid+1, r, k);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = lBinary(nums, 0, nums.size()-1, target);
        int r = rBinary(nums, 0, nums.size()-1, target);
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};
