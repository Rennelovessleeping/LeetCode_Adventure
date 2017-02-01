/**************************************************************************
 * File Name : 310-MinimumHeightTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-01-2017
 *
 * Last Modified : Tue Jan 31 22:21:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution: delete the leaf layer by layer
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph = make_graph(n, edges);
        vector<int> res, pre;
        
        if(n==1) return vector<int> {0};
        
        for(int i=0; i<graph.size();i++){
            if(graph[i].size()==1) pre.push_back(i);
        }
        
        while(true){
            vector<int> cur;
            for(int leaf:pre){
                for(int neigh:graph[leaf]){
                    graph[neigh].erase(leaf);
                    if (graph[neigh].size()==1) cur.push_back(neigh);
                }
            }
            
            if(cur.empty()) return pre;
            pre.swap(cur);
        }
        
        return res;
    }

private:
    vector<unordered_set<int>> make_graph(int n, vector<pair<int, int>>& edges){
        vector<unordered_set<int>> graph(n);
        
        for(auto e:edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        return graph;
    }
    
};

