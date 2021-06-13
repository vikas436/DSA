class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int>mp;
        int res = 0;
        for(int i=0;i<arr.size();i++) {
            int num = 1 + mp[arr[i]-diff];
            mp[arr[i]] = num;
            res = max(res, num);
        }
        return res;
    }
};
