class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>res(T.size(), 0);
        stack<int>stk;
        if(T.empty()) return res;
        stk.push(0);
        int i=1;
        while(i<T.size()) {
            if(stk.empty()) {
                stk.push(i++);
                continue;
            }
            if(T[stk.top()]<T[i]) {
                res[stk.top()] = i-stk.top();
                stk.pop();
            } else {
                stk.push(i++);
            }
        }
        return res;
    }
};
