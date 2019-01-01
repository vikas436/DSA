//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool>&vis, vector<int>*vec, int node) {
    vis[node]=true;
    for(int i=0;i<vec[node].size();i++) {
        if(vis[vec[node][i]]==false) {
            dfs(vis,vec,vec[node][i]);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
     vector<int> vec[n];
     int a,b;
     for(int i=0;i<m;i++) {
         cin>>a>>b;
         a--;b--;
         vec[a].push_back(b);
         vec[b].push_back(a);
     }
    int node;
    cin>>node;
    node--; 
    vector<bool>vis(n,false);
    dfs(vis,vec,node);
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(vis[i]==false) 
            cnt++; 
    } 
    cout<<cnt<<endl;  
    return 0;
}
