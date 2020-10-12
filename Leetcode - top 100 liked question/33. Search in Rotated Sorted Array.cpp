class Solution {
public:
    int binary(vector<int>& vec, int target, int l, int r) {
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(vec[mid]==target) return mid;
        if(vec[mid]>target) {
            if(vec[l]>vec[mid] || vec[l]<=target) {
                return binary(vec, target, l, mid-1);
            } else {
                return binary(vec, target, mid+1, r);
            }
        } else {
            if(vec[r]<vec[mid] || vec[r]>=target) {
                return binary(vec, target, mid+1, r);
            } else {
                return binary(vec, target, l, mid-1);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        return binary(nums, target, 0, nums.size()-1);
    }
};
