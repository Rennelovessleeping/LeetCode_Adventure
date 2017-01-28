/**************************************************************************
 * File Name : 279-PerfectSquares.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-01-2017
 *
 * Last Modified : Fri Jan 27 23:24:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numSquares(int n) {
        // BFS solution:
        if(n<=0) return 0;
        
        vector<int> perfectSquares;
        vector<int> countSquares(n);
        for(int i=1;i*i<=n;i++){
            perfectSquares.push_back(i*i); // find all the possible perfect squares;
            countSquares[i*i-1] = 1; // the least numbers for perfect squares are simply 1;
        }
        
        if(perfectSquares.back()==n) return 1; 
        
        
        queue<int> q;
        int depth = 1;
        for(auto x:perfectSquares) q.push(x);
        
        while(!q.empty()){
            
            depth++;
            int qSize = q.size();
            
            for(int i=0;i<qSize;i++){
                int cur = q.front(); 
                for(auto x:perfectSquares){
                    if (x + cur == n) return depth;
                    else if (x + cur<= n && countSquares[cur+x-1]==0) { 
                        // countSquares is supposed to contain the least numbers
                        countSquares[cur+x-1] = depth;
                        q.push(cur+x);
                    }
                    else if(x + cur>n) break;
                }
                q.pop();
            }
            
        }
        
        return 0;
    }
};

