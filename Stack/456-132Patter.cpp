/**************************************************************************
 * File Name : 456-132Patter.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 14:34:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// brute force solution
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> small, large;
        int i=0;
        
        while(i<nums.size()){
            while(i < nums.size()-1 && nums[i] >= nums[i+1]) i++;
            small.push(make_pair(nums[i],i));
            
            while(i < nums.size()-1 && nums[i] <= nums[i+1]) i++;
            large.push(make_pair(nums[i],i));
            
            for(i+=1; i<nums.size();i++){
                if( nums[i] > small.top().first && nums[i] < large.top().first ) return true;
            }
            
            i = large.top().second + 1;
        }
        
        return false;
    }
};

// O(n) solutiion using stack
class Solution {
public:
    bool find132pattern(vector<int>& nums) { // subsequence s1<s3<s2
        
        stack<int> stk; // candidate pool for next s3 and the bottome is current s2;
        int s3 = INT_MIN;
        
        for(int i=nums.size()-1; i>=0 ;i--){ // nums[i] is candidate for s1
           if(nums[i] < s3) return true;
           else {
               while(!stk.empty() && nums[i] > stk.top()){
                   s3 = stk.top();
                   stk.pop();
               }
           }
           stk.push(nums[i]); // The bottom-up order of stk is descending
         }
        
        return false;
    }

};
