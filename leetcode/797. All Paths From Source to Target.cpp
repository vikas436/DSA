class Solution {
public:
    int len = 0;
    void dfs(vector<int> *vec, vector<int>&path, int ind, vector<vector<int>>&res) {
        if(ind==len) {
            res.push_back(path);
            return;
        }
        for(int i=0;i<vec[ind].size();i++) {
            path.push_back(vec[ind][i]);
            dfs(vec, path, vec[ind][i], res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int>vec[graph.size()];
        for(int i=0;i<graph.size();i++) {
            for(int j=0;j<graph[i].size();j++) {
                vec[i].push_back(graph[i][j]);   
                len = max(len, graph[i][j]);
            }
        }
        vector<int>path;
        path.push_back(0);
        dfs(vec, path, 0, res);
        return res;
    }
};
