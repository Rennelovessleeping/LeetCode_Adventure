/**************************************************************************
 * File Name : 525-ContiguousArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-02-2017
 *
 * Last Modified : Tue Feb 21 15:11:42 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// use Hashtable to record previous accumulation
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int sum = 0, maxLen = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 0)nums[i] = -1;
        }
        
        unordered_map<int, int> mp = {{0, -1}};
        
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i-mp[sum]);
            }
            else mp[sum] = i;
        }
        
        return maxLen;
    }
};
