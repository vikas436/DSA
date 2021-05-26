class Solution {
public:
    int find(vector<int>&uf, int i) {
        if(uf[i] == -1) {
            return i;
        }
        return uf[i] = find(uf, uf[i]);
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int>uf(stones.size(), -1);
        for(int i=0;i<stones.size();i++) {
            for(int j=i+1;j<stones.size();j++) {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) {
                    int x = find(uf, i);   
                    int y = find(uf, j);
                    if(x!=y)
                        uf[x] = y;
                }
            }
        }
        int res=0;
        for(int i=0;i<stones.size();i++) {
            if(uf[i]!=-1) res++;
        }
        return res;
    }
};
