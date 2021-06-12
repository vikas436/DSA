class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        for(int i=1;i<arr.size()-1;) {
            int j=i-1,k=i+1;
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
                res = max(res, k-j+1);
                while(j>0 && arr[j]>arr[j-1]) j--; 
                while(k<arr.size()-1 && arr[k]>arr[k+1]) {
                    k++;
                }
                res = max(res, k-j+1);
            }
            i = max(k, i+1);
        }
        return res;
    }
};
