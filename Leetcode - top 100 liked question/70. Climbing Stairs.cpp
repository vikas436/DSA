class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int>vec(n+1,0);
        vec[1] = 1;
        vec[2] = 2;
        for(int i=3;i<=n;i++) {
            vec[i] = vec[i-1]+vec[i-2];
        }
        return vec[n];
    }
    
    int climbStairsRecursion(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairsRecursion(n-1) + climbStairsRecursion(n-2);
    }
};
                 
