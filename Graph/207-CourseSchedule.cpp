/**************************************************************************
 * File Name : 207-CourseSchedule.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Tue Jan 31 16:21:51 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS to detect loop in directed graph
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = calc_indegree(numCourses, graph);
        
        for(int i=0;i<numCourses;i++){
            int j;
            for(j=0;j<numCourses;j++){
                if(!degrees[j]) break;
            }
            if(j==numCourses) return false;
            degrees[j] = -1; //In case of revisit;
            for(auto x:graph[j]) degrees[x]--;
            
        }
        return true;
    }
    
private:
    vector<unordered_set<int>> buildGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto x:prerequisites) graph[x.second].insert(x.first); // prerequisite -> class might take later
        return graph;
    }
    
    vector<int> calc_indegree(int numCourses, vector<unordered_set<int>> graph){
        vector<int> indegrees(numCourses, 0);
        for(auto pre:graph){
            for(auto x:pre) indegrees[x]++;
        }
        return indegrees;
    }
};

// DFS solution
// A dfs path stemming from a node  should not contain that node;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false); 
        vector<bool> onPath(numCourses, false);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs_cycle(i, visited, onPath, graph)) return false;
        }
        return true;
    }

private:
    vector<unordered_set<int>> buildGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        
        // build hash table to store which course is prerequisite for which;
        for(auto x:prerequisites){
            graph[x.second].insert(x.first);
        }
        return graph;
    }
    
    bool dfs_cycle(int i, vector<bool>& visited, vector<bool>& onPath, vector<unordered_set<int>>& graph){
        if (visited[i]) return false;
        visited[i] = onPath[i] = true;
        for(auto neigh:graph[i]){
            if(onPath[neigh] || dfs_cycle(neigh, visited, onPath, graph)) return true;
        }
        onPath[i] = false;
        return false;
    }
};
