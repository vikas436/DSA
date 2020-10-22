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
    
    int maximalRectangle(vector<vector<char>>& arr) {
        if(arr.empty()) return 0;
        vector<vector<int>>matrix(arr.size(), vector<int>(arr[0].size(), 0));
        for(int i=0;i<arr.size();i++) {
            for(int j=0;j<arr[i].size();j++) {
                if(arr[i][j]=='0') matrix[i][j] = 0;
                else matrix[i][j] = 1;
            }
        }
        int res = largestRectangleArea(matrix[0]);
        for(int i=1;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                if(matrix[i][j]!=0)
                    matrix[i][j] += matrix[i-1][j];
            }
            res = max(res, largestRectangleArea(matrix[i]));
        }
        return res;
    }
};
