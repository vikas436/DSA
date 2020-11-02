class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if(digits.empty()) return res;
        int sum =0 ,carry = 1;
        for(int i=digits.size()-1;i>=0;i--) {
            sum = digits[i] + carry;
            carry = sum/10;
            sum = sum % 10;
            res.push_back(sum);
        }
        if(carry!=0) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
