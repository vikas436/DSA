class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int>l(height.size(),0), r(height.size(),0);
        l[0] = height[0];
        for(int i=1;i<height.size();i++) {
            l[i] = max(height[i], l[i-1]);
        }
        r[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--) {
            r[i] = max(height[i],r[i+1]);
        }
        int res = 0;
        for(int i=0;i<height.size();i++) {
            res += min(l[i], r[i]) - height[i];
        }
        return res;
    }
};
