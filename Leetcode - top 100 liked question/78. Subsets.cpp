class Solution {
public:
    void backtrack(vector<int>& nums, int ind, int size, vector<int>&vec, vector<vector<int>> &res) {
        if(size==0) {
            res.push_back(vec);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            vec.push_back(nums[i]);
            backtrack(nums, i+1, size-1, vec, res);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>> res;
        res.push_back(vec);
        if(nums.empty()) return res;
        for(int i=1;i<nums.size();i++) {
            vec.clear();
            backtrack(nums,0,i, vec, res);
        }
        res.push_back(nums);
        return res;
    }
};
