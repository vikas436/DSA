class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>res;
        if(S.empty()) return res;
        map<char, int>mp;
        for(int i=0;i<S.size();i++) {
            mp[S[i]]=i;
        }
        int window = mp[S[0]], start=0;
        for(int i=0;i<S.size();i++) {
            if(i==window) {
                res.push_back(i-start+1);
                start = i+1;
                if(i!=S.size()-1) window=mp[S[i+1]];
            } else {
                window = max(window, mp[S[i]]);
            }
        }
        if(window==start)
            res.push_back(window-start+1);
        return res;
    }
};
