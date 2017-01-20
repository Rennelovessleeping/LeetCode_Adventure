/**************************************************************************
 * File Name : 215-KthLargestElementInAnArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 19-01-2017
 *
 * Last Modified : Fri Jan 20 14:45:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// nlog(n) solution:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// Priority queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0;i<k-1;i++) pq.pop();
        
        return pq.top();
    }
};

// Quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k-1) return nums[pos];
            if(pos > k-1) right = pos-1;
            else left = pos + 1;
        }
        
        return 0;
    }
    
private:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int orig = left++;
        
        while(left <= right){
            if(nums[left] < pivot && nums[right] > pivot) swap(nums[left++], nums[right--]);
            if(nums[left] >= pivot) left++;
            if(nums[right] <= pivot) right--;
        }
        swap(nums[orig], nums[right]);
        return right;
    }
    
};

// Heap sort, which is the fastest method
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        build_max_heap(nums);
        for(int i=0;i<k;i++){
            swap(nums[0],nums[--heapSize]);
            max_heapify(nums, 0);
        }
        return nums[heapSize];
    }
    
private:
    int heapSize; // Global var changes during the HeapSort;
    inline int left(int idx){ //Idx of left and right child
        return (idx << 1) + 1;
    }
    
    inline int right(int idx){
        return (idx << 1) + 2;
    }
    
    void max_heapify(vector<int>& nums, int idx){ // Put idx element on the right spot
        int maxIdx = idx, l=left(idx), r= right(idx);
        if(l<heapSize && nums[l]>nums[maxIdx]) maxIdx = l;
        if(r<heapSize && nums[r]>nums[maxIdx]) maxIdx = r;
        if(maxIdx != idx){
            swap(nums[maxIdx], nums[idx]);
            max_heapify(nums, maxIdx);
        }
    }
    
    void build_max_heap(vector<int>& nums){
        heapSize = nums.size();
        for(int i=heapSize/2-1;i>=0;i--){ // start from the first node which dont have both children as null children
            max_heapify(nums, i);
        }
    }
    
};
