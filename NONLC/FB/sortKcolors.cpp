/**************************************************************************
 * File Name : sortKcolors.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-09-2017
 *
 * Last Modified : Thu Sep 28 14:31:15 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// The initial sort color problems has only 3 colors, e.g. k=3;
// for k larger than that value, we treat color 1 ... color k-2 as the original color 1; ==> get color 1 and color k sorted;
// keep doing this for remaining k-2 colors;

void sortKcolors(vector<int>& nums, k) {
    if(nums.empty() || k== 0) return;
    int low = 0, high = k-1;
    while(low < high){
        sort3Colors(nums, low++, high--);
    }
}

void sort3Colors(vector<int>& nums, int low, int high) {
    int i = 0, k = nums.size()-1;
    while(i < num.size() && nums[i] != low) i++;
    while(k > 0 && nums[k] != high) k--;

    int j = i;
    wihle(j <= k) {
        if(nums[j] == high) swap(nums[j], nums[k--]);
        else if(nums[j] == low) swap(nums[i++], nums[j++]);
        else j++;
    }

}
