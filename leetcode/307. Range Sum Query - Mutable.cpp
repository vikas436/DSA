class NumArray {
public:
    vector<int>BITree;
    vector<int>arr;
    NumArray(vector<int>& nums) {
        BITree=nums;
        arr=nums;
        BITree.push_back(0);
        for(int i=0;i<BITree.size();i++) BITree[i]=0;
        for(int i=0;i<nums.size();i++) {
            updateTree(i, nums[i]);
        }
    }
    void update(int index, int val) {
        int diff = val-arr[index];
        arr[index]=val;
        index++;
        int n = BITree.size();
        while(index<n) {
            BITree[index]+=diff;
            index += index & (-index);
        }
    }
    
    int sumRange(int left, int right) {
        return getSum(right)-getSum(left-1);
    }
    
    void updateTree(int index, int val) {
        index++;
        int n = BITree.size();
        while(index<n) {
            BITree[index]+=val;
            index += index & (-index);
        }
    }
    
    
    int getSum(int index) {
        int sum = 0;
        index = index + 1;
        while (index>0) {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
