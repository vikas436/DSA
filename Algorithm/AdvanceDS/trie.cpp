// Trie Data Structure
#include <bits/stdc++.h>
using namespace std; 
#define ALPHABET_SIZE 26
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

class TrieNode {
    public:
    TrieNode *trieNode[ALPHABET_SIZE];
    bool isEnd;
    TrieNode() {
        for(int i=0;i<ALPHABET_SIZE;i++) {
            trieNode[i] = NULL;
            isEnd = false;
        }
    }
};
int charToInt(char a) {
    int num = a-'a';
    return num;
}
void addTrieNode(string ch, TrieNode *root) {
  for (int i = 0; i < ch.size(); i++) {
    int num = charToInt(ch[i]);
    if (root->trieNode[num] == NULL) {
      root->trieNode[num] = new TrieNode();
      root = root->trieNode[num];
    } else {
      root = root->trieNode[num];
    }
  }
  root->isEnd = true;
}

void search(string st, TrieNode *root1) {
    bool flagEnd = true;
    FOR(i, 0, st.size()) {
                int j= charToInt(st[i]);
                if(root1->trieNode[j]!=NULL) {
                    root1 = root1->trieNode[j];
                } else {
                    flagEnd = false;
                    break;
                }
        }
    if(flagEnd && root1->isEnd)
        cout <<" => FOUND"<< endl;
    else 
        cout << " => NOT FOUND" << endl;
}

int main() {
    int n;
    cout<<"Number of string want to insert\n";
    cin>>n;
    TrieNode *root = new TrieNode();
    string st;
    FOR(i,0,n) {
        cout<<"Enter string "<<i+1<<endl;
        cin>>st;
        TrieNode *root1 = root;
        addTrieNode(st, root1);
    }
    cout<<"Number of string want to serach\n";
    cin>>n;
    FOR(k, 0, n) {
    cout<<"Enter string "<<k+1<<endl;
        cin>>st;
        TrieNode *root1 = root;
        search(st, root1);
    }

    return 0;
}
