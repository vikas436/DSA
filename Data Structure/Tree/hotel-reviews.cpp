// https://www.interviewbit.com/problems/hotel-reviews/
struct trie {
    int isLast;
    trie *arr[26];
};

trie *getNode() {
    trie *node = new trie();
    for(int i=0;i<26;i++) {
        node->arr[i] = NULL;
    }
    node->isLast=0;
    return node;
}

void insert(trie *root, string str) {
    for(int i=0;i<str.size();i++) {
        int ind = int(str[i] - 'a');
        if(root->arr[ind]==NULL) {
            root->arr[ind] = new trie();
        } 
        root = root->arr[ind];
    }
    root->isLast=1;
}

bool search(trie *root, string str) {
    for(int i=0;i<str.size();i++) {
        int ind = int(str[i] - 'a');
        if(root->arr[ind]==NULL) {
            return false;
        } 
        root = root->arr[ind];
    }
    if(root->isLast==1) return true;
    return false;
}
bool static comp(pair<int,int>pr1, pair<int,int>pr2) {
    if(pr1.first==pr2.first) 
        return pr1.second<pr2.second;
    return pr1.first>pr2.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int > res;
    vector<pair<int, int>> vec;
    
    trie *root = getNode();
    string str="";
    int i=0;
    while(i<A.size()) {
        if(A[i]!='_')
            str= str+A[i];
        if(i==A.size()-1) {
            insert(root, str);
            break;
        }
        if(A[i]=='_') {
            insert(root, str);
            str="";
        }
        i++;
    }
    
    for(int j=0;j<B.size();j++) {
        string str="";
        int cnt=0 , i=0;
        A = B[j];
        while(i<A.size()) {
            if(A[i]!='_')
                str= str+A[i];
            if(i==A.size()-1) {
                if(search(root, str)==true) {
                    cnt++;
                }
                break;
            }
            if(A[i]=='_') {
                if(search(root, str)==true) {
                    cnt++;
                }
                str="";   
            }
            i++;
        }
        vec.push_back(make_pair(cnt, j));
    }
    sort(vec.begin(),vec.end(),comp);
    for(int i=0;i<vec.size();i++) {
        res.push_back(vec[i].second);
    }
    return res;
}
