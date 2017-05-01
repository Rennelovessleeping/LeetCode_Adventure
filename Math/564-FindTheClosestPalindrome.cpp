/**************************************************************************
 * File Name : 564-FindTheClosestPalindrome.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 16:22:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        unordered_set<long> cand;
        cand.insert((int)pow(10, len)+1); // one more digit
        cand.insert((int)pow(10, len-1)-1); // one less digits
        
        long prefix = stol(n.substr(0, (len+1)/2));
        for(int i=-1; i<=1; i++) {
            string tmp = to_string(prefix + i);
            cand.insert(stol(tmp + string(tmp.rbegin() + (1 & len), tmp.rend())));
        }


        long nn = stol(n);
        cand.erase(nn);
        long res = INT_MAX, minDiff = INT_MAX;
        
        for(auto num:cand){
            long diff = abs(num - nn);
            if(diff < minDiff){
                minDiff = diff;
                res = num;
            }
            else if(diff == minDiff) res = min(res, num);
        }
        
        return to_string(res);

    }
};
