class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.size()<=1 || arr[0].size()<=1) return 0;
        int mn = 0, mnind = 0, mx = 0, mxind=0;
        for(int i=0;i<arr.size();i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(mnind==j) {
                    arr[i][j] += mx;
                } else {
                    arr[i][j] += mn;
                }
            }
            mn = INT_MAX, mnind = 0, mx = INT_MAX, mxind=0;
            for(int j=0;j<arr[i].size();j++) {
                if(mn>arr[i][j]) {
                    mx=mn;
                    mxind=mnind;
                    mn=arr[i][j];
                    mnind=j;
                } else if(mx>arr[i][j]) {
                    mx=arr[i][j];
                    mxind=j;
                }
            }
        }
        return mn;
    }
};
