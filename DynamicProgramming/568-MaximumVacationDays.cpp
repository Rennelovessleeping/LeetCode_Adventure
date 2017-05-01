/**************************************************************************
 * File Name : 568-MaximumVacationDays.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 17:07:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int res = 0;
        int N = flights.size(), K = N ? days[0].size() : 0;
        
        // dp[K][N] --> dp[i][j] maximum days if stay staying at city j on i'th week;
        vector<int> dp(N, INT_MIN);
        
        // Initialization: before the first monday, no vacation;
        dp[0] = 0; 
        
        for(int w=0; w<K; w++) { // w'th week
            vector<int> cur(N, INT_MIN); 
            // we need to keep the the INT_MIN as it will denote which city is not arrivable in last round
            for(int i=0; i<N; i++) { // if leave from city i;
                for(int j=0; j<N; j++) { // and end up in city j;
                    if(i==j || flights[i][j]) {
                        cur[j] = max(cur[j], dp[i] + days[j][w]);
                        res = max(res, cur[j]);
                    }
                }
                
            }
            dp.swap(cur);
        }
        
        
        return res;
    }
};
