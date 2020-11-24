class Solution {
public:
    bool static comp(string a1, string b1) {
        string a = a1 + b1;
        string b = b1 + a1;
        return b<a;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        string str = "";
        vector<string> vec(nums.size());
        for(int i=0;i<nums.size();i++) {
            vec[i]=to_string(nums[i]);
        }
        sort(vec.begin(), vec.end(), comp);
        for(int i=0;i<nums.size();i++) {
            str+=vec[i];
        }
        if(vec[0]=="0") return "0";
        return str;
    }
};
