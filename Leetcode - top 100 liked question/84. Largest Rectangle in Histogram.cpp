class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, i = 0;
        stack<int>stk;
        while(i<heights.size()) {
            if(stk.empty() || heights[stk.top()]<=heights[i]) {
                stk.push(i++);
            } else {
                int ind = stk.top(), hist;
                stk.pop();
                hist = (stk.empty()) ? i*heights[ind] : (i-stk.top()-1)*heights[ind];
                res = max(hist, res);
            }
        }
        while(!stk.empty()) {
            int ind = stk.top(), hist;
            stk.pop();
            hist = (stk.empty()) ? i*heights[ind] : (i-stk.top()-1)*heights[ind];
            res = max(hist, res);
        }
        return res;
    }
};
