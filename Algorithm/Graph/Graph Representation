// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/
#include <bits/stdc++.h>
using namespace std;

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
     
     int q;
     cin>>q;
     while(q-->0) {
         cin>>a>>b;
         a--;b--;
         int temp=0;
         for(int i=0;i<vec[a].size();i++) {
             if(vec[a][i]==b) temp=1;
         }
         if(temp==1) cout<<"YES\n"; 
         else cout<<"NO\n";
     }
     
    return 0;
}
