class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i>=grid.size() || i<0 || j>grid[0].size() || j<0) return;
        if(grid[i][j]==1) {
            grid[i][j] = 2;
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size()<=2 || grid[0].size()<=2) return 0;
        for(int i=0;i<grid.size();i++) {
            if(grid[i][0]==1) {
                dfs(grid, i, 0);
            }
            if(grid[i][grid[i].size()-1]==1) {
                dfs(grid, i, grid[i].size()-1);
            }
        }
        for(int i=0;i<grid[0].size();i++) {
            if(grid[0][i]==1) {
                dfs(grid, 0, i);
            }
            if(grid[grid.size()-1][i]==1) {
                dfs(grid, grid.size()-1, i);
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]==1) res++;
                grid[i][j] = (grid[i][j]==2) ? 1 : grid[i][j]; 
            }
        }
        return res;
    }
};
