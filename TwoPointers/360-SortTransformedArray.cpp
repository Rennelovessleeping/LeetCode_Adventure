/**************************************************************************
 * File Name : 360-SortTransformedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-02-2017
 *
 * Last Modified : Fri Feb 24 11:13:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size(), 0);
        for(int i=0; i<res.size(); i++){
            res[i] = a*nums[i]*nums[i] + b*nums[i] + c;
        }
        
        if(a >= 0){
            int i = 0, j = res.size() -1, k = nums.size()-1;
            while(i<=j){
                nums[k--] = j>=0 && res[i] < res[j] ? res[j--] : res[i++];
            }
        }
        else{
            int i = 0, j = res.size() -1, k = 0;
            while(i<=j){
                nums[k++] = j>=0 && res[i] > res[j] ? res[j--] : res[i++];
            }
        }
       
        return nums;
    }
};

// One pass
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        int i = 0, j = nums.size()-1;
        int k = a >= 0 ? nums.size()-1 : 0;
        
        while(i <= j){
            if(a >= 0) res[k--] = quad(nums[i], a, b, c) > quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            else res[k++] = quad(nums[i], a, b, c) < quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
        }
        
        return res;
    }

private:
    int quad(int x, int a, int b, int c){
        return a*x*x + b*x + c;
    }
};
