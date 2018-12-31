// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
     vector<int> vec[n];
     int a,b;
     for(int i=0;i<n-1;i++) {
         cin>>a>>b;
         a--;b--;
         vec[a].push_back(b);
         vec[b].push_back(a);
     }
     
     queue<int> que;
     que.push(0);
     vector<int> dist(n);
     dist[0]=1;
     while(!que.empty()) {
         int cur = que.front();
         que.pop();
         for(int i=0;i<vec[cur].size();i++) {
             if(dist[vec[cur][i]]==0) {
                 que.push(vec[cur][i]);
                 dist[vec[cur][i]] = dist[cur]+1;
             }
         }
     }
     int level,count=0;
     cin>>level;
     for(int i=0;i<n;i++) {
        if(dist[i]==level)
            count++;
        }    
    cout<<count<<endl;         
      
    return 0;
}
