class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(i<nums.size()) {
            if(pq.size()<k) {
                pq.push(nums[i++]);
                continue;
            }
            if(pq.top()<nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
    }
};
