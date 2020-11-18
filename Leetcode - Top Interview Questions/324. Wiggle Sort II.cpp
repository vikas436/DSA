class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        if(n%2 == 0){
            reverse(nums.begin(), nums.begin() + n/2);
        }
        else reverse(nums.begin(), nums.begin() + n/2 +1);
        int left =0;
        int right = n-1;
        while(left <=right){
            ans.push_back(nums[left]);
            if(left != right)ans.push_back(nums[right]);
            left++;
            right--;
        }
        nums = ans;
    }
};
