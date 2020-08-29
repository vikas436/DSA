class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> stk;
        map<char,char>mp;
        mp[']']='[';
        mp['}']='{';
        mp[')']='(';
        for(int i=0;i<s.size();i++) {
            if(s[i]==']' || s[i]=='}' || s[i]==')') {
                if(stk.empty()) return false;
                if(stk.top()==mp[s[i]]) {
                    stk.pop();
                } else return false;
            } else {
                stk.push(s[i]);
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};
