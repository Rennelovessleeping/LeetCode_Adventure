/**************************************************************************
 * File Name : 305-NumberOfIslandsII.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-03-2017
 *
 * Last Modified : Tue Mar  7 20:13:49 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Union Find solution
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        vector<int> parent(m*n, -1);
        int islands = 0;
        
        vector<pair<int, int>> neighbors {{-1,0}, {1,0}, {0,-1}, {0,1}}; 
        for(auto pos:positions){
            islands++;
            int i=pos.first, j = pos.second, idx = pos.first*n + pos.second;
            parent[idx] = idx;
            
            for(auto nebr:neighbors){
                int x = nebr.first + i, y = nebr.second + j, idxNebr = x * n + y;;
                if(x >= 0 && x < m && y >= 0 && y <n && parent[idxNebr] !=-1){
                    int parentCur = findParent(parent, idx), parentNebr = findParent(parent, idxNebr);
                    if(parentCur != parentNebr){
                        islands--;
                        parent[parentCur] = parentNebr;
                    }
                }
            }
            
            res.push_back(islands);
        }
        
        
        return res;
    }
    
private:
    int findParent(vector<int>& parent, int idx){
        while(parent[idx] != idx) idx = parent[idx] = parent[parent[idx]];
        return idx;
    }
    
};
