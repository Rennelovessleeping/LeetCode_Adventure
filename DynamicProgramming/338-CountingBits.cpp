/**************************************************************************
 * File Name : 338-CountingBits.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-01-2017
 *
 * Last Modified : Mon Jan 16 15:34:01 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans={0};
        for(int i=1;i<=num;i++){
            if(i & 1) ans.push_back( 1+ans[i>>1] );
            else ans.push_back( ans[i>>1] );
        }
        return ans;
    }
    
};
