/**************************************************************************
 * File Name : 386-LexicographicalNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-04-2017
 *
 * Last Modified : Tue Apr 25 23:00:17 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    // Tenary Tree;
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for(int i=0; i<n; i++) {
            res[i] = num;
            if(num*10 <= n) num *= 10; // preorder traversal
            else if(num%10 != 9 && num+1<=n) num++; // Move to right sibling
            else {
                while((num/10)%10 == 9) num /= 10; // move to next subtree;
                num = num/10 + 1;
            }
        }
        return res;
    }
};
