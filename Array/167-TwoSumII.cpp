/**************************************************************************
 * File Name : 167-TwoSumII.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 23:35:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two pointer solution
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++){
            for(int j=numbers.size()-1; j>=0; j--){
                if(numbers[i] + numbers[j] == target) return vector<int> {i+1, j+1};
                if(numbers[i] + numbers[j] < target) break;
            }
            while(i<numbers.size()-1 && numbers[i] == numbers[i+1]) i++;
                
        }
        
        return vector<int> {};
    }
};

// Binary Search;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0, right = numbers.size()-1;
        while(numbers[left] + numbers[right] != target){
            if(numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        
        return vector<int> {left+1, right+1};
    }
};
