/**************************************************************************
 * File Name : 169-MajorityElement.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Dec 22 15:34:11 2016
 *
 * Created By :  
**************************************************************************/
// Straightforward hashtable
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int,int> numsVoteMap;
        
        for(int i=0;i<nums.size();i++) numsVoteMap[nums[i]]++;
        
        for(auto const& elem:numsVoteMap){
            if (elem.second>nums.size()/2){
                return elem.first;
            }
            
        }
        return 0;
    }
};

// Divide and Conquer
// Base case for left right half sharing the same majority is trivial; When the majority elemens are different, one needs to compare the count of
// the sub majority element showing in (left, right+1) range;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return subMajority(nums, 0, nums.size() - 1);
    }
private:
    int subMajority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left)/2;
        int leftMajority = subMajority(nums, left, mid);
        int rightMajority = subMajority(nums, mid + 1, right);
        if (leftMajority == rightMajority) return leftMajority;
        return count(nums.begin() + left, nums.begin() + right + 1, leftMajority) > count(nums.begin() + left, nums.begin() + right + 1, rightMajority) ? leftMajority : rightMajority;
    }
}; 

// Randomization
// The idea here is to randomly sample an element from nums until reaching at the majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        srand(unsigned(time(NULL)));
        int randIdx;
        while(true){
            randIdx = rand()%n;
            if(count(nums.begin(), nums.end() , nums[randIdx]) > n/2)
                return nums[randIdx];
            
        }
    }
};

