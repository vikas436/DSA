class Solution {
public:
    bool isPalidrome(string s, int l, int r) {
        while(l<r) {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtracking(string s, vector<vector<string>> &res, vector<string>&vec, int ind) {
        if(ind==s.size()) {
            res.push_back(vec);
            return;
        }
        for(int i = ind; i<s.size();i++) {
            if(isPalidrome(s, ind, i)) {
                vec.push_back(s.substr(ind, i-ind+1));
                backtracking(s, res, vec, i+1);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;
        vector<string>vec;
        backtracking(s, res, vec, 0);
        return res;
    }
};
