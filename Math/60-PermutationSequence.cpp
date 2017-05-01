/**************************************************************************
 * File Name : 60-PermutationSequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 20:02:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums;
        vector<int> factorial(n+1,1);
        
        for(int i=1; i<=n; i++){
            factorial[i] = i*factorial[i-1];
            nums.push_back(i);
        }
        
        k--; // cuz number is zero-based and k/factorial[n-i] trick is also 0-based;
        
        for(int i=1; i<=n; i++){
            int idx = k/factorial[n-i];
            res += to_string(nums[idx]);
            nums.erase(nums.begin()+idx);
            k -= idx*factorial[n-i];
        }
        
        return res;
    }
};
