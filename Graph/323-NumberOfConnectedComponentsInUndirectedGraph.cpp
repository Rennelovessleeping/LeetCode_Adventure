/**************************************************************************
 * File Name : 323-NumberOfConnectedComponentsInUndirectedGraph.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 20:28:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Union find solution
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        for(int i=0; i<edges.size(); ++i){
            int p = edges[i].first;
            int c = edges[i].second;
            while(parent[p] != p) p = parent[p];
            while(parent[c] != c) c = parent[c];
            parent[c] = p;
        }
        unordered_set<int> roots;
        for(auto x: parent) {
            while(parent[x] != x) x = parent[x];
            roots.insert(x);
        }
        return roots.size();
    }
};

// Conciser solution:
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        for(int i=0; i<edges.size(); ++i){
            int p = edges[i].first;
            int c = edges[i].second;
            while(parent[p] != p) p = parent[p];
            while(parent[c] != c) c = parent[c];
            n -= (parent[p] != parent[c]); // the previous two subset containing p and c are now connected by (p,c)
            parent[c] = p;
            
        }
        return n;
    }
};

// Plus path compression
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        for(int i=0; i<edges.size(); ++i){
            int p = edges[i].first;
            int c = edges[i].second;
            while(parent[p] != p) p = parent[p] = parent[parent[p]];
            while(parent[c] != c) c = parent[c] = parent[parent[c]];
            n -= (parent[p] != parent[c]); // the previous two subset containing p and c are now connected by (p,c)
            parent[c] = p;
            
        }
        return n;
    }
};
