class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<values.size();i++) {
            pq.push(make_pair(values[i], labels[i]));
        }
        map<int,int>mp;
        int res=0, limit=0;
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            if(mp[p.second]<use_limit) {
                mp[p.second]++;
                res+=p.first;
                limit++;
            }
            if(limit==num_wanted) return res;
        }
        
        return res;
    }
};
