// https://www.interviewbit.com/problems/letter-phone/
// for better solution refer above link... =>:)
map<char,string>mp;

void getLetter(vector<string>&vec, string A, int l, int r, string str) {
    if(l>=A.size() || r>=mp[A[l]].size()) {
        if(str.size()==A.size())
            vec.push_back(str);
        return;
    } else {
        for(int i=l;i<A.size();i++) {
            for(int j=r;j<mp[A[l]].size();j++) {
                string x1 = mp[A[l]];
                str+= x1[j];
                getLetter(vec, A,i+1,0,str);
                str=str.substr(0,str.size()-1);
            }
        }
    }
}
void setMap() {
    mp.insert(make_pair('0',"0"));
    mp.insert(make_pair('1',"1"));
    mp.insert(make_pair('2',"abc"));
    mp.insert(make_pair('3',"def"));
    mp.insert(make_pair('4',"ghi"));
    mp.insert(make_pair('5',"jkl"));
    mp.insert(make_pair('6',"mno"));
    mp.insert(make_pair('7',"pqrs"));
    mp.insert(make_pair('8',"tuv"));
    mp.insert(make_pair('9',"wxyz"));
}

vector<string> Solution::letterCombinations(string A) {
    setMap();
    vector<string>vec;
    getLetter(vec,A,0,0,"");
    return vec;
}
