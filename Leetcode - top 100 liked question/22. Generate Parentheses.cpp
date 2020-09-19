class Solution {
public:
    void backtrack(vector<string>&res, string str, int n, int open, int closed) {
        if(open==n && closed==n) {
            res.push_back(str);
            return;
        }
        if(closed>open) return;
        if(open<n) {
            backtrack(res, str+"(", n, open+1, closed);
        } 
        if(closed<n) {
            backtrack(res, str+")", n, open, closed+1);
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, 0, 0);
        return res;
    }
};
