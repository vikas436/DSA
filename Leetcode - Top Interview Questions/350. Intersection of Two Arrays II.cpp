class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        multiset <int, greater <int> > mt;        
        for(int i=0;i<nums1.size();i++) {
            mt.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++) {
            if(mt.find(nums2[i])!=mt.end()) {
                res.push_back(nums2[i]);
                mt.erase(mt.find(nums2[i]));
            }
        }
        return res;
    }
};
