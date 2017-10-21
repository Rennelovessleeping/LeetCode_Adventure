/**************************************************************************
 * File Name : 689-MaxSumOf3NonoverlappingSubarrays.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-10-2017
 *
 * Last Modified : Fri Oct 20 17:03:00 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// for the middle interval [i, i+k-1], we need to know the starting idx of max sum interval up to i-1 and also the starting idx starting from i+k;
// we need dp array to memorize the infomation we need.
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxSum = 0;
        vector<int> presum(n+1, 0), res;
        for(int i=1; i<=n; i++) presum[i] = presum[i-1] + nums[i-1];
               
        vector<int> posLeft(n, 0), posRight(n, n-k);
        // update posLeft[i] = starting idx of max sum subarray up to i'th component in nums;
        for(int i=k, tot=presum[k]; i<n; i++) {
            if(presum[i+1] - presum[i+1-k] > tot) {
                posLeft[i] = i+1-k;
                tot = presum[i+1] - presum[i+1-k];
            }
            else posLeft[i] = posLeft[i-1];
        }
        
        // update posRight[i] = starting idx of max sum subarray starting at i'th component in nums;
        for(int i=n-k-1, tot=presum[n]-presum[n-k]; i>=0; i--) {
            if(presum[i+k] - presum[i] >= tot) {
                posRight[i] = i;
                tot = presum[i+k] - presum[i];
            }
            else posRight[i] = posRight[i+1];
        }
        
        // find the middle interval
        for(int m=k; m<=n-2*k; m++) {
            int l = posLeft[m-1], r = posRight[m+k];
            
            int tot = presum[l+k] - presum[l] + presum[m+k]-presum[m] + presum[r+k] - presum[r];
            // cout << l << ", " << m << ", " << r << ": "  << tot << endl;
            if (tot > maxSum) {
                maxSum = tot;
                res = {l, m, r};
            }
        }
        
        // for(auto x:posLeft) cout << x << ", "; cout << endl;
        // for(auto x:posRight) cout << x << ", "; cout << endl;
        
        return res;
    }
};
