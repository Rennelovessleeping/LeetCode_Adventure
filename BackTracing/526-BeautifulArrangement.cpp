/**************************************************************************
 * File Name : 526-BeautifulArrangement.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 16:00:10 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<bool> visited(N+1, false);
        helper(res, visited, 1, N);
        return res;
    }
    
    void helper(int& res, vector<bool>& visited, int pos, int N) {
        if(pos > N) {
            res++;
            return;
        }
        
        for(int i=1; i<=N; i++) { // iterate over number : 1...i...N
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                helper(res, visited, pos+1, N);
                visited[i] = false;
            }
        }
    }
};
