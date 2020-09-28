class Solution {
public:
    int numSquares(int n) {
        vector<int> sq, dp(n + 1, 0);
        for (int i = 1; i * i <= n; i ++)
            sq.push_back(i * i);
        for (int i = 1; i <= n; i ++) {
            long long minv = INT_MAX;
            for (int j = sq.size() - 1; j >= 0; j --){
                if (sq[j] > i) continue;
                minv = min(minv, (long long)dp[i - sq[j]] + 1);
            }
            dp[i] = minv;
        }
        return dp[n];
    }
};
