/**************************************************************************
 * File Name : 152-MaximumProductSubarray.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-12-2016
 *
 * Last Modified : Sat Dec 31 13:58:18 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int len = nums.size();
        if(len == 0) return 0;
                
        int posProd[len] = {nums[0]}; // possibly largest product including i'the component
        int negProd[len] = {nums[0]};
        int maxProd = nums[0];
        
        for(int i=1;i<len;i++){
            posProd[i] = max(max(posProd[i-1]*nums[i], negProd[i-1]*nums[i]), nums[i]);
            negProd[i] = min(min(posProd[i-1]*nums[i], negProd[i-1]*nums[i]), nums[i]);
            maxProd = max(maxProd, posProd[i]);
        }
        
        return maxProd;
        
    }
};

// Optimized DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Largest product is determined by how many negative numbers are there in the array
        int len = nums.size();
        int minProd=nums[0], maxProd=nums[0], ans=nums[0];
        
        for(int i=1;i<len;i++){
            if(nums[i]<0) swap(minProd,maxProd);
            maxProd = max(maxProd*nums[i], nums[i]);
            minProd = min(minProd*nums[i], nums[i]);
            ans = max(ans, maxProd);
        }
        
        return ans;
    }
};

// Two pointers
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Largest product is determined by how many negative numbers are there in the array
        int len = nums.size();
        int frontProd=1, backProd=1, ans=INT_MIN;
        
        for(int i=0;i<len;i++){
            
            frontProd *= nums[i];
            backProd *= nums[len-1-i];
            ans = max(ans, max(frontProd, backProd));
            frontProd = frontProd==0 ? 1: frontProd;
            backProd = backProd==0 ? 1: backProd;
        }
        
        return ans;
    }
};
