/**************************************************************************
 * File Name : 327-CountOfRangeSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-03-2017
 *
 * Last Modified : Wed Mar 22 23:11:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Divide and Conquer solution using binary search
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0 || lower > upper) return 0;
        return countRangeSum(nums, lower, upper, 0, nums.size()-1);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper, int l, int r){
        if(l == r) return nums[l] >= lower && nums[r] <= upper;
        
        int mid = l + (r-l)/2;
        vector<long> prefix(r-mid,0);
        long int sum = 0;
        for(int i=mid+1; i<=r; i++){
            sum += nums[i];
            prefix[i-(mid+1)] = sum; 
        }
        
        sort(prefix.begin(), prefix.end());
        sum = 0;
        int count = 0;
        for(int i=mid; i>=l; i--){
            sum += nums[i];
            count += findIdx(prefix, upper-sum+0.5) - findIdx(prefix, lower-sum-0.5); // length;
        }
        
        return count + countRangeSum(nums, lower, upper, l, mid) + countRangeSum(nums, lower, upper, mid+1, r);
        
    }
private:
    int findIdx(const vector<long>& arr, double target){ // search for the one-pass-end idx
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};

// DC solution based on prefix arr
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> prefix(len+1, 0);
        for(int i=1; i<=len; i++){
            prefix[i] = prefix[i-1] + nums[i-1]; 
        }
        return countRangeSum(prefix, lower, upper, 0, len);
    }
    
private:
    int countRangeSum(vector<long>& prefix, int lower, int upper, int left, int right){
        if(right <= left) return 0;
        int mid = left + (right-left)/2;
        int res = countRangeSum(prefix, lower, upper, left, mid) + countRangeSum(prefix, lower, upper, mid+1, right);
        
        vector<long> mergedArr(right-left+1, 0);
        int i = left, j = mid+1, k = 0;
        int p = mid+1, q = mid+1; // two-pointer looking for i2 supposing i1 in first half;
        while(i <= mid){
            // The left and right part has already been sorted;
            while(p <= right && prefix[p]-prefix[i] < lower) p++;
            while(q <= right && prefix[q]-prefix[i] <= upper) q++; // both stop at pass-by-one
            res += q - p;
            while(j <= right && prefix[j] < prefix[i]) mergedArr[k++] = prefix[j++];
            mergedArr[k++] = prefix[i++];
        }
        while(j <= right) mergedArr[k++] = prefix[j++];
        
        swap_ranges(mergedArr.begin(), mergedArr.end(), prefix.begin()+left);
        return res;
    }
};


