/**************************************************************************
 * File Name : 307-RangSumQueryMutable.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-03-2017
 *
 * Last Modified : Thu Mar 23 22:06:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Solution based on segment tree;
class NumArray {
public:
    struct segmentTreeNode{
        int start, end;
        int sum;
        segmentTreeNode *left, *right;
        
        segmentTreeNode(int start, int end): sum(0), left(nullptr), right(nullptr) {
            this->start = start;
            this->end = end;
        }
    };
    
    NumArray(vector<int> nums) {
        root = buildSegmentTree(nums, 0, nums.size()-1);
    }
    
    void update(int i, int val) {
        return update(root, i, val);
    }
    
    void update(segmentTreeNode* root, int i, int val){
        if(root->start == i && root->end == i) {
            root->sum = val;
            return;
        }
        
        int mid = root->start + (root->end - root->start)/2;
        if(i <= mid) update(root->left, i, val);
        else update(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
    
    int sumRange(segmentTreeNode* root, int start, int end ){
        if(root->start == start && root->end == end) return root->sum;
        
        int mid = root->start + (root->end - root->start)/2;
        if(end <= mid) return sumRange(root->left, start, end);
        else if(start >=  mid+1) return sumRange(root->right, start, end);
        else return sumRange(root->left, start, mid) + sumRange(root->right, mid+1, end);
        
    }
    
private:
    segmentTreeNode *root = nullptr;
    segmentTreeNode* buildSegmentTree(const vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        
        segmentTreeNode *root = new segmentTreeNode(start, end);
        if(start == end) root->sum = nums[start];
        else{
            int mid = start + (end-start)/2;
            root->left = buildSegmentTree(nums, start, mid);
            root->right = buildSegmentTree(nums, mid+1, end);
            root->sum = root->left->sum + root->right->sum;
        }
        
        return root;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

// BIT solution
class NumArray {
public:
    vector<int> nums;
    vector<long> BIT;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        this->nums = nums;
        BIT = vector<long> (n+1, 0);
        for(int i=0; i<n; i++) init(i, nums[i]);
    }
    
    void init(int i, int val){
        i++;
        while(i<=n){
            BIT[i] += val;
            i += (i&-i);
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        init(i, diff);
    }
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
    
    int getSum(int i){
        int res = 0;
        i++;
        while(i>0) {
            res += BIT[i];
            i -= (i & -i);
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
