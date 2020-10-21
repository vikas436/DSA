class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if(nums.empty() || k==0) return vec;
        deque<pair<int,int>> dq;
        int i=0;
        while(i<k) {
            if(i==0) {
                dq.push_back(make_pair(nums[i], i));
                i++;
                continue;
            }
            while(!dq.empty() && dq.back().first<=nums[i]) {
                  dq.pop_back();
            }
            dq.push_back(make_pair(nums[i], i));
            i++;
        }
        vec.push_back(dq.front().first);
        while(i<nums.size()) {
            if((i-k)==dq.front().second) dq.pop_front();
            if(dq.empty()) {
                dq.push_back(make_pair(nums[i], i));
            } else {
                while(!dq.empty() && dq.back().first<=nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(make_pair(nums[i], i));
            }
            vec.push_back(dq.front().first);
            i++;
        }
        return vec;
    }
};
