/**************************************************************************
 * File Name : 133-CloneGraph.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Mon Jan 30 21:33:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // In case of any possible loop, build a hash table
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloned;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        if(cloned.find(node)==cloned.end()){
            cloned[node] = new UndirectedGraphNode(node->label);
            for(int i=0;i<node->neighbors.size();i++){
                cloned[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        
        return cloned[node];
    }
};

