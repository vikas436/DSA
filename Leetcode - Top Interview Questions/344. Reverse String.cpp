class Solution {
public:
    void recursion(vector<char>& vec, int i, int j) {
        if(i>j) return;
        swap(vec[i], vec[j]);
        recursion(vec, i+1, j-1);
    }
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        recursion(s, 0, s.size()-1);
    }
};
