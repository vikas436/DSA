class Solution {
public:
    vector<vector<char>> init;
    const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool recursion(vector<vector<char>>& board, string word, int i,int j,int ind) {
        if(word.size()==ind) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j] != word[ind]) return false;
        board[i][j] = '-';
        for (const auto& dir : dirs) {
            if (recursion(board, word, i + dir[0], j + dir[1], ind + 1)) {
                board[i][j] = init[i][j];
                return true;
            }
        }
        board[i][j] = init[i][j];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        init=board;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<char>> board1 = board;
                    if(recursion(board1, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
