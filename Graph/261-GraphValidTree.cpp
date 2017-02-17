/**************************************************************************
 * File Name : 261-GraphValidTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 20:24:57 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use union find in undirected graph
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // first of all no cycle; secondly n-1 edges make the graph connected
        if(edges.size()!=n-1) return false;
        
        // detect any possible loop:
        vector<int> parent(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        for(int i=0; i<edges.size(); ++i){
            int p = edges[i].first;
            int c = edges[i].second;
            while(parent[p] != p) p = parent[p];
            while(parent[c] != c) c = parent[c];
            if(parent[p] == parent[c]) return false;
            parent[c] = p;
        }
        return true;
        
    }
};


