class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        for(int i=0;i<=n-1;i++) {
            for(int j=i+1;j<=n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<=n;i++) {
            int l=0,r=n;
            while(l<r) {
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};
