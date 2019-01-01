//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

#include <bits/stdc++.h>
using namespace std;

class graph {
public:
int x,y,weight;
    graph(int x,int y,int weight) {
        this->x=x;
        this->y=y;
        this->weight=weight;
    }
    graph(){}
};

static bool comp(graph a, graph b) {
    return a.weight<b.weight;
}

int rootkey(vector<int>&root, int x) {
    while(root[x]!=x) {
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unionSet(int x, int y, vector<int>&root) {
    int a = rootkey(root, x);
    int b = rootkey(root, y);
    root[a] = root[b];
}

int Kruskals(vector<graph> vec, vector<int>&root) {
    int cost=0;
    for(int i=0;i<vec.size();i++) {
        int x,y,weight;
        x = vec[i].x;
        y = vec[i].y;
        weight = vec[i].weight;

        if(rootkey(root, x)!=rootkey(root, y)) {
            cost+=weight;
            unionSet(x,y, root);
        }
    }
    return cost;
}
int main() {
    int n,m;
    cin>>n>>m;
     
     int a,b,weight;
     vector<graph>gr(m);
     for(int i=0;i<m;i++) {
         cin>>a>>b>>weight;
         a--;b--;
         gr[i] = graph(a, b, weight);
     }

    sort(gr.begin(), gr.end(), comp);
    vector<int>root(n);
    for(int i=0;i<n;i++)
        root[i]=i;
    
    cout<<Kruskals(gr, root)<<endl;
    return 0;
}
