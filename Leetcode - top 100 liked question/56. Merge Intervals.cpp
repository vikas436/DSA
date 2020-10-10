class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int>vec;
        vec.push_back(intervals[0][0]);
        vec.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();i++) {
            if(vec[1]>=intervals[i][0]) {
                vec[1] = max(intervals[i][1], vec[1]);
            } else {
                res.push_back(vec);
                vec.clear();
                vec.push_back(intervals[i][0]);
                vec.push_back(intervals[i][1]);
            }
        }
        if(!vec.empty()) res.push_back(vec);
        return res;
    }
};
