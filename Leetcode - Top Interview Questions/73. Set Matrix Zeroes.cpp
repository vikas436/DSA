class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size(), row=0, column=0;
        //mark the border if 0 exits
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                row = 1;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                column = 1;
                break;
            }
        }
        
        //find 0 in matrix[i][j] and mark the border
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //fill 0 by the marked border
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //rewrite the border if 0 exists
        if(row){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(column){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        
    }
};
