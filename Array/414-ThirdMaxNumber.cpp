/**************************************************************************
 * File Name : 414-ThirdMaxNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-12-2016
 *
 * Last Modified : Fri Dec 23 12:10:55 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int thirdMax(vector<int>& nums) {;
        
        /*
        // Building set from vector is slow O(nlgn);
        set<int> uniNums (nums.begin(), nums.end());
        if(uniNums.size()<3){
            return *uniNums.rbegin();
        }

        else return *(++(++uniNums.rbegin()));
        */
        
        // Use quene
        set<int> topThree;
        int len = nums.size();
        for(int i=0;i<len;i++){
            topThree.insert(nums[i]);
            if (topThree.size() >3) topThree.erase(topThree.begin());
        }
        
        return topThree.size() < 3 ? *topThree.rbegin() : *topThree.begin();

    }
};



