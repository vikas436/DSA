class Solution {
public:
    string getString(string s, int i, int j) {
        string str = "";
        for(int k=i;k<=j && k<s.size();k++) {
            str+=s[k];
        }
        return str;
    }
    string palindromeOdd(string s, int i, int j) {
        string str;
        int l=i,r=j;
        i--;
        j++;
        while(i>=0 && j<s.size()) {
            if(s[i]==s[j]) {
                l=i;r=j;
                i--;
                j++;
            } else break;
        }
        str = getString(s,l,r);
        return str;
    }
    string palindromeEven(string s, int i, int j) {
        string str;
        int l=0,r=0;
        while(i>=0 && j<s.size()) {
            if(s[i]==s[j]) {
                l=i;r=j;
                i--;
                j++;
            } else break;
        }
        str = getString(s,l,r);
        return str;
    }
    string longestPalindrome(string s) {
        string res="";
        if(s.size()==0) return res;
            
        for(int i=0;i<s.size();i++) {
            string odd = palindromeOdd(s,i,i);
            string even = palindromeEven(s,i,i+1);
            if(res.size()<odd.size()) res = odd;
            if(res.size()<even.size()) res = even;
        }
        return res;
    }
};
