class Solution {
public:
    long reverse(long long x) {
        if(x<=2147483648 && x>=-2147483647) {
            
        } else return 0;
        long long num=1,val=0;
        while(x) {
            int rem = x %10;
            x = x / 10;
            val = val*10+rem;
            num=num*10;
        }
        
        if(val<=2147483648 && val>=-2147483647) {
            return val;
        } else return 0;
    }
};
