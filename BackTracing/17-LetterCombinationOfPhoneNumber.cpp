/**************************************************************************
 * File Name : 17-LetterCombinationOfPhoneNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-01-2017
 *
 * Last Modified : Fri Jan 13 17:43:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//Backtracking solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        helper(string(), digits, 0);
        return ans;
    }
    
private:
    vector<string> ans;
    unordered_map<char, vector<char>> t{
        {'2', {'a', 'b', 'c'}},    
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    
    void helper(string chars, string digits, int used){
        if (used == digits.size()){
            ans.push_back(chars);
            return;
        }
        
        if (t.find(digits[used])!=t.end()){
            for(int i=0;i<t[digits[used]].size();i++){
                chars += t[digits[used]][i];
                helper(chars, digits, used+1);
                chars.pop_back();
            }
        }

    }
    
};

// Enumeration
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return vector<string>();
        vector<string> ans(1); // Initialization
        
        for(int i=0;i<digits.size();i++){
            vector<string> tmp;
            int num = digits[i] -'0';
            if(num<0 || num>9) break;
            for(int j=0; j<ans.size(); j++){
                for(int k=0;k<t[num].size();k++){
                    tmp.push_back(ans[j] + t[num][k]);
                }
            }
            ans.swap(tmp);
        }
        
        return ans;
    }
private:
    vector<string> t = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
};
