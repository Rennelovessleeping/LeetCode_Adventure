/**************************************************************************
 * File Name : 219-ContainDupII.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-12-2016
 *
 * Last Modified : Fri Dec 23 13:28:53 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Beyond time limit
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        //nums = vector<int> {1,0,1,1};
        //k = 1;
        
        if (nums.size() <= k+1) return simpleCmp(nums);
        int i;
        for(i=0; i < nums.size()-k ;i++){
            vector<int> subNums (nums.begin()+i, nums.begin()+i+k+1);
            if (simpleCmp(subNums)){
                return simpleCmp(subNums);
            }
        }

        return false;
    }
    
private:
    bool simpleCmp(vector<int>& subNums){
        set<int> uniNums(subNums.begin(), subNums.end());
        return subNums.size()!=uniNums.size();
        
    }
    
    
};

// Use regular set is slow since insert involves sorting. 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int len = nums.size();
        set<int> kBlock;
        for(int i=0;i<len;i++){
            if (i>k) kBlock.erase(nums[i-k-1]);
            if(!kBlock.insert(nums[i]).second) return true;
        }
        
        return false;
    }
};

// Using unordered_set follows the same idea as set. But insertion here is faster.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int len = nums.size();
        unordered_set<int> kBlock;
        for(int i=0;i<len;i++){
            if (i>k) kBlock.erase(nums[i-k-1]);
            if(kBlock.find(nums[i]) != kBlock.end()) return true;
            kBlock.insert(nums[i]);
        }
        
        return false;
    }
};
