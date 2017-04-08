/**************************************************************************
 * File Name : 363-MaxSumOfRectangleNoLargerThanK.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-04-2017
 *
 * Last Modified : Sat Apr  8 12:10:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if(m == 0 || n == 0) return 0;
        int res = INT_MIN;
        
        for(int i = 0; i<n; i++) {
            vector<int> presum(m, 0); // presum[k]: accumulated sum of i'th col between current two rows[i,j];
            for(int j=i; j<n; j++) {
                for(int k=0; k<m; k++) presum[k] += matrix[k][j];
                
                set<int> tmp;
                tmp.insert(0);
                int cursum = 0, curmax = INT_MIN;
                for(const auto& pre:presum) {
                    cursum += pre;
                    auto it = tmp.lower_bound(cursum - k);
                    if(it != tmp.end()) curmax = max(curmax, cursum - *it);
                    tmp.insert(cursum);
                }
                res = max(res, curmax);
            }
        }
        
        return res;
    }
};
