class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > vec( m , vector<int> (n, 0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) {
                    vec[0][0]=grid[0][0];
                }
                else if(i==0) {
                    vec[i][j] = grid[i][j] + vec[i][j-1];
                } else if(j==0) {
                    vec[i][j] = grid[i][j] + vec[i-1][j];
                } else {
                    vec[i][j] = grid[i][j] + min(vec[i-1][j], vec[i][j-1]);         
                }
            }
        }
        return vec[m-1][n-1];
    }
};
