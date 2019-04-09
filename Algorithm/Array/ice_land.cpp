#no of iceland in n*m matrix...
#include <bits/stdc++.h>
using namespace std;

void iceLand(vector< vector<int> > &vec, int i, int j, int n, int m) {
    if(i>=n || j>=m || i<0 || j<0) return;
    if(vec[i][j]==0 || vec[i][j]==-1) return;
    vec[i][j]=-1;
    iceLand(vec, i+1,j,n,m);
    iceLand(vec, i-1,j,n,m);
    iceLand(vec, i,j+1,n,m);
    iceLand(vec, i,j-1,n,m);
    iceLand(vec, i+1,j+1,n,m);
    iceLand(vec, i-1,j+1,n,m);
    iceLand(vec, i+1,j-1,n,m);
    iceLand(vec, i-1,j-1,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< vector<int> >vec(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>vec[i][j];
    
    int iceland = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(vec[i][j]==1) {
                iceland++;
                iceLand(vec, i, j, n, m);
            }
        }
    }
    cout<<"# of ice lands: "<<iceland;    
    return 0;
}
