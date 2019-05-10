// https://leetcode.com/problems/word-search/
class Solution {
public:
    int num = 0;

    void dfs(vector< vector<char> >&vec,vector< vector<int> >arr,int i, int j,int n, int m, string str, int ind) {
      if(ind>=num && ind<=str.size()) {
          num = ind;
      }
    if (num == str.size()) {
              return;
     }
      if (i > 0 && arr[i - 1][j] == -1 &&
          vec[i - 1][j] == str[ind]) {
        arr[i - 1][j] = arr[i][j] + 1;
        dfs(vec, arr, i - 1, j, n, m, str, ind + 1);
          arr[i - 1][j] = -1;
      }
      if (i < n - 1 && arr[i + 1][j] == -1 &&
          vec[i + 1][j] == str[ind]) {
        arr[i + 1][j] = arr[i][j] + 1;
        dfs(vec, arr, i + 1, j, n, m, str, ind + 1);
          arr[i + 1][j] = -1;
      }
      if (j > 0 && arr[i][j - 1] == -1 &&
          vec[i][j - 1] == str[ind]) {
        arr[i][j - 1] = arr[i][j] + 1;
        dfs(vec, arr, i, j - 1, n, m, str, ind + 1);
          arr[i][j-1] = -1;
      }
      if (j < m - 1 && arr[i][j + 1] == -1 &&
          vec[i][j + 1] == str[ind]) {
        arr[i][j + 1] = arr[i][j] + 1;
        dfs(vec, arr, i, j + 1, n, m, str, ind + 1);
          arr[i ][j+1] = -1;
      }
    }

    bool solve(vector< vector<char> >&vec,int n, int m, string str) {
        vector< vector<int> >arr(n, vector<int>(m, -1));
            for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                if(vec[i][j]==str[0])  {
                    arr[i][j]=0;
                    dfs(vec, arr, i, j, n, m, str, 1); 
                    arr[i][j]=-1;
                    if (num == str.size()) return true;
                }
              }
            }
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        return solve(board, board.size(),board[0].size(),word);
    }
};
