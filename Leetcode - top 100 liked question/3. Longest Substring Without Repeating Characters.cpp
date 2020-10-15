class Solution {
public:
    bool isDuplicate(vector<int>vec) {
        for(int i=0;i<vec.size();i++) {
            if(vec[i]>1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        vector<int>vec(256, 0);
        int i=0,j=0, res=0;
        while(i<s.size()) {
            int ind = s[i];
            vec[ind]++;
            if(isDuplicate(vec)) {
                while(j<i && isDuplicate(vec)) {
                    ind = s[j];
                    if(vec[ind]>0) {
                        vec[ind]--;
                    }
                    j++;
                }
            }
            res = max(res, i-j+1);
            i++;
        }
        return res;
    }
};
