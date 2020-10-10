class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector< vector<int> > dp(n, vector<int>(m, 0));
        int res = 0;
        for(int i=0;i<n;i++) {
            dp[i][0] = matrix[i][0]=='1' ? 1 : 0;
            res = max(res, dp[i][0]);
        }
        for(int i=0;i<m;i++) {
            dp[0][i] = matrix[0][i]=='1' ? 1 : 0;
            res = max(res, dp[0][i]);
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j]=='1') {
                    bool isTrue = matrix[i-1][j]=='1' &&
                                  matrix[i][j-1]=='1' && 
                                  matrix[i-1][j-1]=='1';
                    dp[i][j] = 1 + (isTrue ? min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) : 0);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res; 
    }
};
