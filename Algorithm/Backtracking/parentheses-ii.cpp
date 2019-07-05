// https://www.interviewbit.com/problems/generate-all-parentheses-ii/
// refer to link for better solution...!
set<string>st;
bool checkParen(string str) {
    stack<char>stk;
    int i=0;
    while(i<str.size()) {
        if(str[i]=='(') {
            stk.push('(');
        } else {
            if(stk.empty()) return false;
            if(stk.top()!='(') return false;
            stk.pop();
        }
        i++;
    }
    if(stk.empty()) return true;
    return false;
}
bool shouldSwap(string str, int start, int curr) 
{ 
    for (int i = start; i <curr; i++)  
        if (str[i] == str[curr]) 
            return 0; 
    return 1; 
} 
void getParen(string str,int l, int r) {
    if(l>=r) {
        if(checkParen(str)){
            if(st.find(str)==st.end()) st.insert(str);
        }
    } else {
        for(int i=l;i<r;i++) {
            if(shouldSwap(str,l,i)) {
                swap(str[i],str[l]);
                getParen(str,l+1,r);
                swap(str[i],str[l]);   
            }
        }
    }   
}

vector<string> Solution::generateParenthesis(int A) {
    string str="";
    for(int i=0;i<A;i++) str+="(";
    for(int i=0;i<A;i++) str+=")";
    getParen(str,0,2*A-1);
    vector<string>vec;
    for(auto it=st.begin();it!=st.end();it++) {
        vec.push_back(*it);
    }
    st.clear();
    return vec;
}
