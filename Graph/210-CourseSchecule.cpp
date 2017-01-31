/**************************************************************************
 * File Name : 210-CourseSchecule.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Tue Jan 31 16:32:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> order;
        vector<unordered_set<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = calc_indegree(numCourses, graph);
        
        for(int i=0;i<numCourses;i++){
            int j;
            for(j=0;j<numCourses;j++){
                if(!degrees[j]) {
                    order.push_back(j);
                    break;
                }
            }
            if(j==numCourses) return vector<int>();
            degrees[j] = -1; //In case of revisit;
            for(auto x:graph[j]) degrees[x]--;
            
        }
        return order;
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

// DFS-topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false); 
        vector<bool> onPath(numCourses, false);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs_cycle(i, visited, onPath, graph)) return vector<int>();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    vector<int> ans;
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
        ans.push_back(i);
        onPath[i] = false;
        return false;
    }
};

