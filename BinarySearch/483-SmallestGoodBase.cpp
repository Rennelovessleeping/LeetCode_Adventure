/**************************************************************************
 * File Name : 483-SmallestGoodBase.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 20:15:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// 1 + k + k^2 + ... k^d == n; we conduct a binary search to find k given d;
// smallest base k = 2, biggest base = n-1;
class Solution {
public:
    string smallestGoodBase(string n) {
        
        unsigned long long tn = (unsigned long long)stoll(n);
        unsigned long long tmp = 1;
        for(int i=62; i>=1; i--) {
            if((tmp<<i) < tn) {
                unsigned long long cur = helper(tn, i);
                if(cur) return to_string(cur);
            }
        }
        
        return to_string(tn-1);
    }
    
    unsigned long long helper(unsigned long long n, int d) {

        unsigned long right = (unsigned long) (pow((double) n, 1.0/d)+1);
        unsigned long left = 1;
        while(left <= right) {
            unsigned long long mid = left + (right-left)/2;
            unsigned long long sum = 1;
            unsigned long long cur = 1;
            for(int i=1; i<=d; i++) {
                cur *= mid;
                sum += cur;
            }
            
            if(sum == n) return mid;
            if(sum > n) right = mid-1;
            else left = mid+1;
        }
        
        return 0;
    }
};
