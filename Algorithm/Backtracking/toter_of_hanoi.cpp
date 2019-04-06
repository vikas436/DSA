#include <bits/stdc++.h>
using namespace std;

void fun(int t, int from, int to, int temp) {
    if(t==1){
        cout<<" move from "<< from<< " to "<<to<<endl;
        return;
    } else {
        fun(t-1, from, temp, to);
        cout<<" move from "<< from<< " to "<<to<<endl;
        fun(t-1, temp, to, from);
    }
}

int main() {
  int n;
  cin>>n;
  fun(n, 1,3,2);
  return 0;
}
