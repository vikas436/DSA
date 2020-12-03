class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0, cursum=0, tank=0,ind=0;
        for(int i=0;i<gas.size();i++) {
            tank = gas[i]-cost[i];
            if(tank>tank+cursum) {
                ind=i;
                cursum= tank;
            } else {
                cursum+=tank;
            }
            sum+=tank;
        }
        return (sum>=0) ? ind : -1;
    }

