// Refer=> https://www.interviewbit.com/problems/palindrome-partitioning/

set<vector<string>>seet;
bool isPalind(string str, int i, int j) {
    while(i<j) {
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}
void isPalindrome(vector<int>vec, string str) {
    int num=0;
    vector<string>rs;
    for(int i=1;i<vec.size();i++) {
        if(i-1==0) {
            if(isPalind(str, vec[i-1], vec[i])){
                rs.push_back(str.substr(vec[i-1],vec[i]-vec[i-1]+1));
                num++;
             }
                else return;
        } else if(i==vec.size()-1) {
            if(vec[i]==vec[i-1]) break;
            if(isPalind(str, vec[i-1]+1, vec[i])){
                 num++;
                rs.push_back(str.substr(vec[i-1]+1,(vec[i]-(vec[i-1]+1)+1)));
            }
                else return;
        } else {
            if(isPalind(str, vec[i-1]+1,vec[i])){
                 num++;
                rs.push_back(str.substr(vec[i-1]+1,(vec[i]-(vec[i-1]+1)+1)));
            }
            else return;
        }
    }
    if(seet.find(rs)==seet.end())
        seet.insert(rs);
}

void comb(vector<int>&vec,string str, int k,int ind) {
    if(k==0) {
        vector<int>temp=vec;
        temp.insert(temp.begin(),1,0);
        temp.push_back(str.size()-1);
        isPalindrome(temp,str);
        return ;
    } else {
        for(int i=ind;i<str.size();i++) {
            vec.push_back(i);
            comb(vec,str, k-1, i+1);
            vec.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector< vector<string> >res;
    for(int i=0;i<A.size();i++) {
        vector<int>vec;
        comb(vec,A,i+1,0);
    }
    for(auto it=seet.begin();it!=seet.end();it++) {
            res.push_back(*it);
    }
    seet.clear();
    return res;
}
