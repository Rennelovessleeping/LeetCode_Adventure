/**************************************************************************
 * File Name : 367-ValidPerfectSquare.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-01-2017
 *
 * Last Modified : Sun Jan 22 19:56:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long int root = num;
        while(root*root > num){
            root = (root + num/root)/2;
        }
        return root*root == num; 
    }
};
