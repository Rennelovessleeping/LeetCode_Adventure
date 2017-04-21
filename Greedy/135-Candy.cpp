/**************************************************************************
 * File Name : 135-Candy.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 21:09:42 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) return n;
        vector<int> res(n, 1);
        
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) res[i] = res[i-1] + 1;
        }
        
        for(int i=n-1; i>0; i--) {
            if(ratings[i-1] > ratings[i]) res[i-1] = max(res[i]+1, res[i-1]); 
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};
