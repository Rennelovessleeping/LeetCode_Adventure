/**************************************************************************
 * File Name : 179-LargestNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 15:21:09 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> strs(nums.size());
        for(int i;i<nums.size();i++){
            strs[i] = to_string(nums[i]);
        }
        
        sort(strs.begin(), strs.end(), [](string& str1, string& str2){return str1+str2 > str2+str1;} );
        
        string ans;
        for(auto s:strs) ans += s;
        
        while(ans[0]=='0' && ans.size()>1) ans.erase(0,1); // in case of all zeros string
        
        return ans;
        
    }
    
};
