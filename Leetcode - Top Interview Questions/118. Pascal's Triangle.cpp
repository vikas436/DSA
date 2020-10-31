class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        vector<int>vec1;
        for(int i=0;i<n;i++) {
            vector<int>vec2;
            for(int j=0;j<=i;j++) {
                if(j==0 || j==i) {
                    vec2.push_back(1);
                } else {
                    vec2.push_back(vec1[j]+vec1[j-1]);
                }
            }
            res.push_back(vec2);
            vec1 = vec2;
        }
        return res;
    }
};
