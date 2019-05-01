// https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/
#include <bits/stdc++.h>
using namespace std;

int repeatNBy3(vector<int>& vec) {
    int cnt1=0,cnt2=0,cnt3=0;
    int val1 = -100000, val2 = -100000,val3=-100000;
    for(int i=0;i<vec.size();i++) {
        if(vec[i]==val1) cnt1++;
        else if(vec[i]==val2) cnt2++;
        else if (vec[i] == val3) cnt3++;
        else{
            if(cnt1>0 && cnt2>0 && cnt3>0) {
                cnt1--;cnt2--;cnt3--;
            } else {
                if(cnt1==0) {
                    val1=vec[i];
                    cnt1=1;
                } else if(cnt2==0) {
                    val2 = vec[i];
                    cnt2=1;
                } else if(cnt3==0) {
                    val3=vec[i];
                    cnt3=1;
                }
            }
        }
    }
    cnt1=0;cnt2=0;cnt3=0;
    for(int i=0;i<vec.size();i++) {
        if(val1==vec[i]) cnt1++;
        if(val2==vec[i]) cnt2++;
        if (val3 == vec[i]) cnt3++;
    }
    int n3 = vec.size()/3;
    if(cnt1>n3) return val1;
    if (cnt2 > n3) return val2;
    if (cnt3 > n3) return val3;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout << repeatNBy3(vec);
    return 0;
}
