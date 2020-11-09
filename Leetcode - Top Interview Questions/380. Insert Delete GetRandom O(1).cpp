class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int>st;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(st.find(val)!=st.end()) return false;
        st.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(st.find(val)==st.end()) return false;
        st.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return *next(st.begin(), rand() % st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
