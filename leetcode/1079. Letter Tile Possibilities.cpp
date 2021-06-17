class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int>counts(26, 0);
        for (int i=0;i<tiles.size();i++) {
            counts[tiles[i] - 'A']++;
        }
        int result = 0;
        rec(counts, result);
        return result;
    }
    
    void rec(vector<int>counts, int &result) {
        for(int i = 0; i < 26; ++i) {
            if (counts[i]) {
                counts[i]--;
                rec(counts, ++result);
                counts[i]++;
            }
        }
    }
};
