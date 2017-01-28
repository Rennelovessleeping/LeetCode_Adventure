/**************************************************************************
 * File Name : 204-CountPrimes.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-01-2017
 *
 * Last Modified : Sat Jan 28 12:40:49 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool> primes(n, true);
        primes[0]= false; primes[1] = false;
        int upper = sqrt(n);
        
        for(int i=2;i<=upper;i++){
            if(primes[i]){
                for(int j=i*i; j<n; j+=i) primes[j] = false;
            }
        }
        
        return count(primes.begin(), primes.end(), true);
    }
};
