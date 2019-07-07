//  https://www.interviewbit.com/problems/sudoku/


vector<vector<char> > res;
bool allDone(vector<vector<char> > &A, int &row, int &col) {
    for (row = 0; row < A.size(); row++)  
        for (col = 0; col < A.size(); col++)  
            if (A[row][col] == '.')  
                return true;  
    return false;  
}
bool isSafe(vector<vector<char> > &A, int row, int col,int num) {
    for(int i=0;i<A.size();i++) {
        if(A[row][i]=='0'+num) return true;
    }
    for(int i=0;i<A.size();i++) {
        if(A[i][col]=='0'+num) return true;
    }
    row = row - row % 3;
    col = col - col % 3;
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (A[i+row][j+col] == '0'+num)  
                return true;  
    return false; 
}
void sudoku(vector<vector<char> > &A) {
    int row=0,col=0;
    if(!allDone(A,row,col)) {
        res=A;
        return;
    }
    for(int i=1;i<=9;i++) {
        if(!isSafe(A,row,col,i)) {
            A[row][col]='0'+i;
            sudoku(A);
            A[row][col]='.';
        }
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    sudoku(A);
    A=res;
    res.clear();
}
