/**************************************************************************
 * File Name : 241-DifferentWayToAddParentheses.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 16:11:25 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        
        for(int i=0; i<input.size(); i++){
            char cur = input[i];
            if(cur == '+' || cur == '-' || cur == '*') {
                vector<int> res1 = diffWaysToCompute(input.substr(0,i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
                
                for(const auto& n1:res1) {
                    for(const auto& n2:res2) {
                        if(cur == '+') res.push_back(n1 + n2);
                        else if(cur == '-') res.push_back(n1 - n2);
                        else res.push_back(n1 * n2);
                    }
                }
            }
        }
        
        if(res.empty()) res.push_back(stoi(input));
        
        return res;
    }
};
