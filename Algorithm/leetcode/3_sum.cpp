// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> threeSum(vector<int> &nums) {
   sort(nums.begin(), nums.end());
   vector<vector<int>> res;
   int k = 0;
   unordered_set<string> st;
   for (int i = 0; i < nums.size(); i++) {
     if (i + 3 < nums.size() && nums[i] == nums[i + 3])
       continue;
     k = nums.size() - 1;
     for (int j = i + 1; j < nums.size(); j++) {
       vector<int> vec;
       string str = "";
       while ((nums[i] + nums[j] + nums[k]) >= 0 && k > j && k >= 0) {
         if ((nums[i] + nums[j] + nums[k]) == 0) {
           vec.push_back(nums[i]);
           vec.push_back(nums[j]);
           vec.push_back(nums[k]);
           str += to_string(nums[i]);
           str += to_string(nums[j]);
           str += to_string(nums[k]);
           break;
         }
         k--;
       }
       if (vec.size() > 0 && st.find(str) == st.end()) {
         res.push_back(vec);
         st.insert(str);
       }
     }
   }
   for (int i = 0; i < res.size(); i++) {
     for (int j = 0; j < res[i].size(); j++) {
       cout << res[i][j] << " ";
     }
     cout << endl;
   }
   return res;
 }

 int main() {
   int n;
   cin >> n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
     cin >> arr[i];
   threeSum(arr);
   return 0;
}
