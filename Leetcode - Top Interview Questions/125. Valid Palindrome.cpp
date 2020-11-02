class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i=0,j=s.size()-1;
        while(i<j) {
            if(!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) {i++;continue;}
            if(!((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))) {j--;continue;}
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
