class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {to_string(nums[0])};
        vector<string> res;
        string st="",en="";
        st += to_string(nums[0]);
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]+1 != nums[i]) {
                if(en=="") {
                    res.push_back(st);   
                } else res.push_back(st+"->"+en);
                st = to_string(nums[i]);
                en="";
            } else {
                en=to_string(nums[i]);
            }
            if(i==nums.size()-1) {
                if(en=="") {
                    res.push_back(st);   
                } else res.push_back(st+"->"+en);
            }
        }
        return res;
    }
};
