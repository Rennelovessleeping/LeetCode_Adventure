/**************************************************************************
 * File Name : 364-NestedListWeigthSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-03-2017
 *
 * Last Modified : Fri Mar 10 15:49:29 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use hashtable to record depth and corresponding sum and do postprocessing later;
// note that mp.size() does not have to be the maximum depth!!
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        dfs(nestedList, 1);
        if(mp.empty()) return 0;
        for(int i=(*mp.rbegin()).first, level=1; i>0; i--, level++){
            res += mp[i]*level;
        }
        return res;
    }
private:
    map<int, int> mp; //{depth:level sum}
    void dfs(vector<NestedInteger>& nestedList, int depth){
        for(auto tmp : nestedList){
            if(tmp.isInteger()) mp[depth] += tmp.getInteger();
            else dfs(tmp.getList(), depth+1);
        }
    }
};

// level order traversal
// res += sum calculates weighted sum
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0, sum = 0;
        queue<vector<NestedInteger>> q;
        for(auto list:nestedList){
            if(list.isInteger()) sum += list.getInteger();
            else q.push(list.getList());
        }
        res += sum;
        
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len ;i++){
                auto tmp = q.front(); q.pop();
                for(auto list:tmp){
                    if(list.isInteger()) sum += list.getInteger();
                    else q.push(list.getList());
                }
            }
            res += sum;
        }
        
        return res;
    }
    
};

