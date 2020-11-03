class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool>prime(n, 0);
        for(int i=2;i<n;i++) {
            if(prime[i]) continue;
            for(int j=i;i+j<n;j=j+i) {
                prime[i+j] = 1;
            }
        }
        int res=0;
        for(int i=2;i<n;i++) {
            if(!prime[i]) res++;
        }
        return res;
    }
};
