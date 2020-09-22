class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int i = 0, j = n-1, res = 0;
        for(;i<j;) {
            res = max(res, (j-i)*min(height[i], height[j]));
            if(height[i]<height[j])
                i++;
            else j--;
        }
        return res;
    }
};
