// https://www.interviewbit.com/problems/nqueens/

vector< vector<string> > data;
void prnt(vector< vector<string> >vec) {
    string str="";
    for(int i=0;i<vec.size();i++) {
        for(int j=0;j<vec.size();j++) {
            str+=vec[i][j];
        }
        if(i<vec.size()-1)str+=" ";
    }
    vector<string>vc;
    vc.push_back(str);
    data.push_back(vc);
}
bool issafe(vector< vector<string> >&vec, int i, int j) {
    for(int k=0;k<vec.size();k++)
        if(vec[k][j]=="Q") return false;
    for(int k=0;k<vec.size();k++)
        if(vec[i][k]=="Q") return false;
        int l=i,m=j;
    while(l>=0 && m>=0) {
        if(vec[l][m]=="Q") return false;
        l--;m--;
    }
    l=i;m=j;
    while(l<vec.size() && m>=0) {
        if(vec[l][m]=="Q") return false;    
        l+=1;m-=1;
    } 
    return true;
}
void nQueen(vector< vector<string> >&vec, int j) {
    if(j==vec.size()){ prnt(vec);return;}
        for(int l=0;l<vec.size();l++) {
            if(issafe(vec, l, j)) {
                vec[l][j]="Q";
                nQueen(vec, j+1);
                vec[l][j]=".";
            } 
        }
}
vector<vector<string> > Solution::solveNQueens(int n) {
    vector< vector<string> > res(n, vector<string>(n,"."));
    nQueen(res, 0);
    vector< vector<string> > data1=data;
    data.clear();
    return data1;
}    
