class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return 0;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0) {
            if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
            else return 1;
        }
        return 0;
    }
};
