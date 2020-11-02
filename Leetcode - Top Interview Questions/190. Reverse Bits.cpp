class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string str="";
        for(int i=0;i<32;i++) {
            str+=to_string(n%2);
            n=n/2;
        }
        reverse(str.begin(), str.end());
        uint32_t p=0,num=0;
        for(int i=0;i<str.size();i++) {
            if(str[i]=='1')
                num+=pow(2, i);
        }
        return num;
    }
};
