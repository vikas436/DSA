class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if(a[0] == b[0]){ 
            return a[1] < b[1];
        }
        else{
            return a[0] > b[0]; 
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if(people.empty()) return res;
        sort(people.begin(),people.end(),comp);
        for(auto p:people){
            res.insert(res.begin()+p[1],p);  
        }
        return res;
    }
};
