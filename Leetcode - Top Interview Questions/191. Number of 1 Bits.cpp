class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        string str="";
        while(n>0)
        {
            str+=to_string(n%2);
            n/=2;
        }
        
        for(int i=0;i<str.size();i++) {
            if(str[i]=='1') res++;
        }
        return res;
    }
};
