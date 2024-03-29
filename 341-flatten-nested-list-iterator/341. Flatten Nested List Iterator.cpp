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

void flatten(vector<NestedInteger> &nestedList, int idx, vector<int> &v){
    if (idx >= nestedList.size()) return;

    if (nestedList[idx].isInteger()){
        v.push_back(nestedList[idx].getInteger());
    }
    else flatten(nestedList[idx].getList(), 0, v);
    flatten(nestedList, idx + 1, v);
}

class NestedIterator {
public:
    vector<int> v;
    int idx = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList, 0, v);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */