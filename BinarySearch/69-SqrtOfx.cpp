/**************************************************************************
 * File Name : 69-SqrtOfx.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-01-2017
 *
 * Last Modified : Sun Jan 22 12:49:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search
class Solution {
public:
    int mySqrt(int x) {
        
        long int left = 0, right = x;
        while(left <= right){
            long int mid = left + (right-left)/2;
            if(mid*mid == x) return mid;
            else if(mid * mid > x) right = mid - 1;
            else left = mid + 1;
        }
        
        return right;
         
    }
};

// Newton's iteration
class Solution {
public:
    int mySqrt(int x) {
        
        long int root = x;
        while(root*root > x){
            root = (x/root + root)/2;
        }
        
        return root;
         
    }
};

