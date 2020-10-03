class Solution {
public:
    char PADDING = '2';
    void recursion(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size()) return;
        if(grid[i][j]=='1') {
            grid[i][j] = PADDING;
            recursion(grid, i+1, j);
            recursion(grid, i, j+1);
            recursion(grid, i-1, j);
            recursion(grid, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.empty()) return res;
        for(int i = 0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    recursion(grid, i, j);   
                    res++;
                }
            }
        }
        return res;
    }
};
