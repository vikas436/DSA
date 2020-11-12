class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int>vec[n];
        vector<int>inDegree(n, 0);
        for(int i=0;i<arr.size();i++) {
            vec[arr[i][1]].push_back(arr[i][0]);
            inDegree[arr[i][0]]++;
        }
        
        int ind=0,num;
        vector<int> res;
        while(ind<n) {
            num=-1;
            for(int i=0;i<n;i++) {
                if(inDegree[i]==0 && inDegree[i]!=-1) {
                    num = i;
                    inDegree[i] = -1;
                    break;
                }
            }
            if(num==-1) return {};
            res.push_back(num);
            for(int i=0;i<vec[num].size();i++) {
                inDegree[vec[num][i]]--;
            }
            ind++;
        }
        return res;
    }
};
