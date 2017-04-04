/**************************************************************************
 * File Name : 547-FriendCircles.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-04-2017
 *
 * Last Modified : Tue Apr  4 15:08:35 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        
        vector<int> parent(n);
        for(int i=0; i<parent.size(); i++) parent[i] = i;
        
        int res = n;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(!M[i][j]) continue;
                int pi = find(parent, i), pj = find(parent, j);
                if(pi == pj) continue;
                parent[pi] = pj;
                res--;
            }
        }
        return res;
    }

private:    
    int find(const vector<int>& parent, int p){
        while(parent[p] != p) p = parent[parent[p]];
        return p;
    }
    
};
