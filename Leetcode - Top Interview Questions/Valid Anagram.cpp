class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vecs(26, 0), vect(26, 0);
        for(int i=0;i<s.size();i++) {
            vecs[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++) {
            vect[t[i]-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(vecs[i]!=vect[i]) return false;
        }
        return true;
    }
};
