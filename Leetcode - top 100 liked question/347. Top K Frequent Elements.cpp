class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        map<int,vector<int>>ans;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        vector<int> res;
        priority_queue <int> pq;
        for(auto m : mp) {
            if(ans.find(m.second)==ans.end())
                pq.push(m.second);
            ans[m.second].push_back(m.first);
        }
        while(!pq.empty()) {
            vector<int> v = ans[pq.top()];
            for(int i=0;i<v.size() && res.size()<k;i++)
                res.push_back(v[i]);
            pq.pop();
        }
        return res;
    }
};
// time complexity = distinctNums*logN
