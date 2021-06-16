class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>vec(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(word1[i-1]==word2[j-1]) {
                    vec[i][j] = 1+vec[i-1][j-1];
                } else {
                    vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
                }
            }
        }
        return (n+m)-2*vec[n][m];
    }
};
