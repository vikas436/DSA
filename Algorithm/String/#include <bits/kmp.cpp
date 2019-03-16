// kmp algorithm 
#include <bits/stdc++.h>
using namespace std;

void lps(string st, vector<int>&vec) {
    int i=0,j=0;
    for(i=1; i<st.size();) {
        if(st[j] == st[i]) {
            vec[i] = j+1;
            i++;
            j++;
        } else {
            if(j != 0) {
                j = vec[j-1];
            } else {
                i++;
            }
        }
    }
}

void kmp(string st, string pt) {
    vector<int> vec(pt.size());
    lps(pt, vec);
    int i=0,j=0;
    for(;i<st.size();) {
        if(st[i]==pt[j]) {
            i++;
            j++;
        } else {
            if(j != 0) {
                j = vec[j-1];
            } else {
                i++;
            }
        }
        if(j==pt.size()-1) cout<<i-j<<endl;
    }

}
int main()
{
    string st,pt;
    cin>>st>>pt;
    kmp(st,pt);
    return 0;
}
