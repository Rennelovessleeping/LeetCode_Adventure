/**************************************************************************
 * File Name : 332-ReconstructIniterary.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-02-2017
 *
 * Last Modified : Fri Feb  3 14:42:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution to find the Euerian path

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        map<string, multiset<string>> graph = make_graph(tickets);
        vector<string> ans;
        dfs(ans, "JFK", graph);
        
        return vector<string> (ans.rbegin(), ans.rend());
    }

private:
    map<string, multiset<string>> make_graph(vector<pair<string, string>>& tickets){
        // there could be possibly duplicate tickets
        map<string, multiset<string>> graph;
        for(auto t:tickets){
            graph[t.first].insert(t.second);
        }
        return graph;
    }
    
    void dfs(vector<string>& ans, string airport, map<string, multiset<string>>& graph){
        while(!graph[airport].empty()){
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(ans, next, graph);
        } // ends up when loop is stuck in a node without any departing tickets any more
        ans.push_back(airport);
    }
    
};


