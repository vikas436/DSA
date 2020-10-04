class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, unordered_map<long, int>> pmap;
        for(int i=0; i < nums.size(); i++){
            int v=nums[i];
            if(i==0){
                pmap[0][v]++;
                pmap[0][-v]++;
            } else {
                for(auto k : pmap[i-1]){
                    pmap[i][k.first + v] += pmap[i-1][k.first];
                    pmap[i][k.first - v] += pmap[i-1][k.first];
                }
            }
        }
        return pmap[nums.size()-1][S];
    }
};
