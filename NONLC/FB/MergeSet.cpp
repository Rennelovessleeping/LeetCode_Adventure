/**************************************************************************
 * File Name : MergeSet.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-10-2017
 *
 * Last Modified : Sun Oct 22 20:53:15 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
//2. 给一些sets，保证每个set内元素不重复，如果两个sets有任何共同元素，则让其合并，直到不能合并为止。输出最后的sets的状态。
// Input: {1,2},{2,3},{3,4}{5,6,7},{7,8},{9},{9}. visit 1point3acres.com for more.
// Output: {1,2,3,4},{5,6,7,8},{9}

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<vector<int>> mergeSet(vector<vector<int>>& sets) {
    unordered_map<int, vector<int>> res;
    unordered_map<int, unordered_set<int>> mp;
    unordered_set<int> unique;
    
    for(auto& set:sets) {
        sort(set.begin(), set.end());
        for(auto x:set) unique.insert(x);
        for(int i=1; i<set.size(); i++){
            mp[set[i-1]].insert(set[i]);
        }
    }
    
    unordered_map<int, int> parent;
    for(auto& item:unique) parent[item] = item;
    
    for(auto& item:mp){
        int p = item.first;
        for(auto c:item.second) {
            while(parent[p] != p) p = parent[parent[p]];
            while(parent[c] != c) c = parent[parent[c]];
            if(p == c) continue;
            parent[c] = p;
        }
    }
    
    for(auto x:unique) {
        int x_copy = x;
        while(parent[x] != x) x = parent[parent[x]];
        res[x].push_back(x_copy);
    }
    
    vector<vector<int>> res_vec;
    for(auto item:res) res_vec.push_back(item.second);
    
    return res_vec;
}

int main() {
    vector<vector<int>> sets = {{1,2},{2,3},{3,4},{5,6,7},{7,8},{9},{9}};
    vector<vector<int>> res = mergeSet(sets);
    for(auto set:res) {
        for(auto x:set) cout << x << ", ";
        cout << endl;
    }
    
    return 0;
}
