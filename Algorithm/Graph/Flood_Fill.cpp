//https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

#include <bits/stdc++.h>

using namespace std;

bool floodFill(vector<vector<int>>vec,int x,int y,int n,int m,vector<vector<int>>vis){
    if(x<0 || y<0) return false;
    if(x>=n || y>=m) return false;
    if(x==n-1 && y==m-1) return true;
    if(vis[x][y]==1) return false;
    vis[x][y]=1;
    if(vec[x][y]==1) {
        if(floodFill(vec,x-1,y,n,m,vis)==true) return true;
        if(floodFill(vec,x+1,y,n,m,vis)==true) return true;
        if(floodFill(vec,x,y-1,n,m,vis)==true) return true;
        if(floodFill(vec,x,y+1,n,m,vis)==true) return true;
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< vector<int> >vec(n, vector<int>(m));
    vector< vector<int> >vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>vec[i][j];
    if(floodFill(vec,0,0,n,m,vis)==1) 
    cout<<"Yes";
    else cout<<"No";

   return 0;
}
