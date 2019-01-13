#include <bits/stdc++.h>
using namespace std;
#define INF 10000000007

class bellmanFord{
    public:
        long int src,dest,weight;
        bellmanFord(long int a, long int b, long int c) {
            src = a;
            dest = b;
            weight = c;
        }
        bellmanFord(){}
};

void bellmanFordAlgo(int src, bellmanFord edgeList[], int vertices, int edges) {
    vector<long int>dist(vertices,INF);
    dist[src]=0;
    for(int v=0;v<vertices-1;v++) {
        for(int i=0;i<edges;i++){
            if(dist[edgeList[i].dest]>(dist[edgeList[i].src]+edgeList[i].weight)) {
                 dist[edgeList[i].dest] = dist[edgeList[i].src]+edgeList[i].weight;
            }
      }
    }
    

    for(int i=0;i<vertices;i++)
        if(i!=src){
            if(dist[i]!=INF) cout<<dist[i]<<" ";
            else cout<<"1000000000 ";
        }
}

int main()
{
    int vertices,edges;
    scanf("%d%d",&vertices,&edges);
    bellmanFord edgeList[edges];
    for(int i=0;i<edges;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        edgeList[i] = bellmanFord(a,b,c);
    }
    bellmanFordAlgo(0, edgeList, vertices, edges);

    return 0;
}
