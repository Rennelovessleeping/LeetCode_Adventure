/**************************************************************************
 * File Name : 255-VerifyPreorderSequenceInBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-02-2017
 *
 * Last Modified : Thu Feb 23 23:21:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use stack to record all the ancesters
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        // push the ancesor and right child in stk, so current lower bond should always be smaller than the next visted number
        stack<int> stk;
        int low = INT_MIN;
        for(auto num:preorder){
            if (num < low) return false;
            while(!stk.empty() && stk.top() < num){
                low = stk.top();
                stk.pop();
            }
            stk.push(num);
        }
        
        return true;
    }
};
