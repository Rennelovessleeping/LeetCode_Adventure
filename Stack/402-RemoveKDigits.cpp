/**************************************************************************
 * File Name : 402-RemoveKDigits.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 00:24:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Using stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.length()==0 || num.length()<=k) return "0";
        int keep = num.length() - k;
        string res;
        
        for(int i=0;i<num.size();i++){
            while (res.size()>0 && res.back()>num[i] && k>0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        
        int nonzero = 0;
        while(nonzero<res.size() && res[nonzero] == '0') {nonzero++;}
        res.erase(0, nonzero);
            
        return res == "" ? "0" : res;
        
    }
    
};
