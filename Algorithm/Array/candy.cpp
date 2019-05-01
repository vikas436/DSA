// https://leetcode.com/problems/candy/
class Solution {
public:
    int candy(vector<int>& vec) {
    vector<int>arr(vec.size(),1);
    
    for(int i=0;i<vec.size()-1;i++) {
        if(vec[i+1]>vec[i]) {
            arr[i+1]=arr[i]+1;
        }
    }    
    for(int i=vec.size()-1;i>0;i--) {
        if(vec[i-1]>vec[i] && arr[i-1]==1) {
            arr[i-1]=arr[i]+1;
        }
    }
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i]>vec[i+1] && arr[i]<=arr[i+1]) arr[i]=arr[i+1]+1;
    }
        
    int sum=0;
    for(int i=0;i<vec.size();i++){
        cout<<arr[i]<<" ";
         sum+=arr[i];
    }
    return sum;
}
};
