class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;
        for(int i=0;i<=num;i++) {
            unsigned int count = 0, n=i;
            while (n) { 
                count += n & 1; 
                n >>= 1; 
            } 
            res.push_back(count);
        }
        return res;
    }
};
