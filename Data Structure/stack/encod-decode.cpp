#include <bits/stdc++.h>

using namespace std;

void pattern(string str) {
        stack<char>stk;
        for(int i=0;i<str.size();i++) {
            if(str[i]==']'){
                    string temp="";
                    while(stk.top()!='[') {
                        temp+=stk.top();
                        stk.pop();
                    }
                    reverse(temp.begin(),temp.end());
                    stk.pop();
                    string num="";
                    while(!stk.empty() && (stk.top()>='0' && stk.top()<='9')) {
                        num+=stk.top();
                        stk.pop();
                    }
                    reverse(num.begin(),num.end());
                    stringstream geek(num); 
                    int n = 0; 
                    geek >> n; 
                    string merge="";
                    for(int j=0;j<n;j++) {
                        merge+=temp;
                    }
                    for(int j=0;j<merge.size();j++) {
                        stk.push(merge[j]);
                    }
             }
                    
                else 
                    {
                        stk.push(str[i]);
                    }
        }
        string ret = "";
        while(!stk.empty()) {
            ret+=stk.top();
            stk.pop();
        }
        reverse(ret.begin(),ret.end());
        cout<<ret<<endl;
    }

int main()
{
    string st;
    cin>>st;
    pattern(st);
    return 0;
}
// test case
//3[abcd2[pq]]2[yz]
