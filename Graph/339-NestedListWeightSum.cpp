/**************************************************************************
 * File Name : 339-NestedListWeightSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-03-2017
 *
 * Last Modified : Fri Mar 10 15:19:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
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
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
    
private:
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int res= 0;
        for(auto tmp:nestedList){
            res += tmp.isInteger() ? depth*tmp.getInteger() : dfs(tmp.getList(), depth+1);
        }
        
        return res;
        
    }
};
