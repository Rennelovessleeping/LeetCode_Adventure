/**************************************************************************
 * File Name : 553-NextGreaterNumberIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-04-2017
 *
 * Last Modified : Wed Apr 12 17:31:51 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Same idea as next permutation;
// can use the std::next_permutation directly if we convert the number to a string first of all
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> num;
        while(n) {
            num.push_back(n%10);
            n /= 10;
        }
        reverse(num.begin(), num.end());
        
        int i = num.size() - 1;
        for(; i>0 && num[i-1] >= num[i]; i--) {}
        
        if(i>0) {
            int j = num.size() - 1;
            for(; j>i && num[j] <= num[i-1]; j--) {}
            swap(num[i-1], num[j]);
            reverse(num.begin()+i, num.end());
            
            long res = 0;
            for(int k=0; k<num.size(); k++) res = res*10 + num[k];
            return res > INT_MAX ? -1 : res;
        }
        
        return -1;
    }
};
