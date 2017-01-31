/**************************************************************************
 * File Name : 210-CourseSchecule.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Mon Jan 30 23:07:58 2017
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

