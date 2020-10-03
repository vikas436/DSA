class Solution {
public:
    map<char,string>mp;
    void preparePad() {
        if(!mp.empty()) return;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    }
    
    void backtracking(string digits, string &str, int ind, vector<string> &res) {
        if(str.size()==digits.size()) {
            res.push_back(str);
            return;
        }
        for(int i=0;i<mp[digits[ind]].size();i++) {
            str.push_back(mp[digits[ind]][i]);
            backtracking(digits, str, ind+1, res);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        preparePad();
        string str="";
        backtracking(digits, str, 0, res);
        return res;
    }
};
