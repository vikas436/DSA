/*
    Can enhance using trie,
    save the matched path in trie and start searching where word match matching failed
*/
class Solution {
public:
    const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool recursion(vector<vector<char>>& board, string word, int i,int j,int ind) {
        if(word.size()==ind) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j] != word[ind]) return false;
        char old = board[i][j];
        board[i][j] = '-';
        for (const auto& dir : dirs) {
            if (recursion(board, word, i + dir[0], j + dir[1], ind + 1)) {
                board[i][j] = old;
                return true;
            }
        }
        board[i][j] = old;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        for(int i=0;i<words.size();i++) {
            if(exist(board, words[i])) res.push_back(words[i]);
        }
        return res;
    }
};
