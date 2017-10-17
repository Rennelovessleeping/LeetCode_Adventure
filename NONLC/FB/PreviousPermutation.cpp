/**************************************************************************
 * File Name : PreviousPermutation.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-09-2017
 *
 * Last Modified : Thu Sep 28 22:49:33 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
void prev_permutation(string& str) { // find lexicographically smaller permuation "4321" -> "4312"
    int n = s.size(), i=n-1;
    // find largest i with str[i] < str[i-1] ==> first decreasing pair, e.g. '21'
    while(i>0 && str[i-1] <= str[i]) i--;
    
    if(i > 0){
        int j = i-1;
        while(j+1<n && str[j+1] <= str[i-1]) j++;
        swap(str[i-1], str[j]);
    }

    reverse(s.begin()+i, s.end());
}

// For comparison
void nextPermutation(vector<int>& nums) { // "1234" -> "1243"
        // Find the increasing from the back
        int i = nums.size()-1;
        for(; i>0 && nums[i-1] >= nums[i]; i--) {}
        
        // Find the first element larger than nums[i-1];
        if(i > 0){
            int j = nums.size()-1;
            for(; j>=i && nums[j] <= nums[i-1]; j--) {}
            swap(nums[i-1], nums[j]);
        }
        
        reverse(nums.begin()+i, nums.end());
    }
