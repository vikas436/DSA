class Solution {
public:
    vector<int> vec, temp;
    
    Solution(vector<int>& nums) {
        vec = nums;
        temp = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        temp = vec;
        for(int i=0;i<vec.size();i++) {
            int v = i + ((1+rand())%(vec.size()-i));
            swap(temp[i], temp[v]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
