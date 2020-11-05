/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int>que;
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        int num = que.front();
        que.pop();
        return num;
    }
    
    bool hasNext() {
        return !que.empty();
    }
    
    void helper(vector<NestedInteger> l) {
        if (l.empty())
          return;
        for (auto &e : l) {
          if (e.isInteger()) {
            que.push(e.getInteger());
          } else {
            auto nl = e.getList();
            helper(nl);
          }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
