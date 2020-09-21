class Solution {
public:
    set<vector<int>>st;
    
    void backtracking(vector<int>& candidates, int sum, int target, vector<int>&vec) {
        if(sum>target) return;
        if(sum==target) {
            vector<int>temp = vec;
            sort(temp.begin(), temp.end());
            st.insert(temp);        
            return;
        }
        for(int i=0;i<candidates.size();i++) {
            vec.push_back(candidates[i]);
            backtracking(candidates, sum+candidates[i], target, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>vec;   
        backtracking(candidates, 0, target, vec);
        vector<vector<int>> res;
        for(auto it : st) {
            res.push_back(it);
        }
        return res;
    }
};
