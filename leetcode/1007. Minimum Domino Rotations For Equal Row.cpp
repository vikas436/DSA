class Solution {
public:
    int min(int a, int b) {
        if(a<b) return a;
        return b;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        if(tops.size()<=1) return 0;
        int res = 0;
        int t = tops[0], b = bottoms[0];
        int tcnt = 0, bcnt = 0;
        int ist = 1, isb = 1;
        for(int i=1;i<tops.size();i++) {
            if(t==tops[i] || t==bottoms[i]) ist++;
            if(b==tops[i] || b==bottoms[i]) isb++;
            
            if(t!=tops[i]) tcnt++;
            if(b!=bottoms[i]) bcnt++;
        }
        if(ist==tops.size() && isb==tops.size()) {
            return min(min(tcnt, tops.size()-tcnt), min(bcnt, tops.size()-bcnt));
        } else if(ist!=tops.size() && isb!=tops.size()) return -1;
        
        if(ist==tops.size()) {
            t = tops[0];
            b = tops[0];
            tcnt=0;
            bcnt=1;
        } else {
            t = bottoms[0];
            b = bottoms[0];
            tcnt=1;
            bcnt=0;
        }
       
        for(int i=1;i<tops.size();i++) {
            if(t!=tops[i]) tcnt++;
            if(b!=bottoms[i]) bcnt++;
        }
        return min(min(tcnt, tops.size()-tcnt), min(bcnt, tops.size()-bcnt));
    }
};
