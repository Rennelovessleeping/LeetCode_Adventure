/**************************************************************************
 * File Name : 313-SuperUglyNumbers.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-01-2017
 *
 * Last Modified : Sat Jan 28 15:18:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(), primes.end());
        vector<int> pos(primes.size(),0);
        
        vector<int> superUglyNums(n);
        superUglyNums[0] = 1;
        for(int i=1;i<n;i++){
            superUglyNums[i] = INT_MAX;
            for(int j=0;j<primes.size();j++){ 
             superUglyNums[i] = min(superUglyNums[i], primes[j] * superUglyNums[pos[j]]);
             
            }
            for(int j=0;j<primes.size();j++){
                // Note that multiple pos of primes can be updated
                if(superUglyNums[i] == primes[j] * superUglyNums[pos[j]] ) pos[j]++;
            }
            
        }
        
        return superUglyNums[n-1];
    }
};

