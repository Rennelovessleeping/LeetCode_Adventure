/**************************************************************************
 * File Name : 678-ParenthesesInAString.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-09-2017
 *
 * Last Modified : Fri Sep 22 14:43:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// characterize the validness of parenthese string using an integer rather than a stack
class Solution {
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);    
    }
    
    bool dfs(string s, int pos, int count) {
        if(count < 0) return false;
        
        for(int i=pos; i<s.size(); i++) {
            if(s[i] == '(') count++;
            else if(s[i] == ')') {
                count--;
                if(count < 0) return false;
            }
            else return dfs(s, i+1, count+1) || dfs(s, i+1, count-1) || dfs(s, i+1, count);
        }
        
        return count == 0;
    }
};


// we can optimize this backtracing solution to a linear time solution based on the idea of stack. But we actually use an integer.
// When introducing * in the string , it acutually change the number of unpaired parentheses in to a range. As long as zero falls 
// in the final range, the string is valid
class Solution {
public:
    bool checkValidString(string s) {
        // one pass linear solution
        int lower = 0, upper = 0;
        
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '(') lower++, upper++;
            else if (s[i] == ')') lower--, upper--;
            else lower--, upper++;
            
            lower = max(lower, 0);
            if(upper < 0) return false;
        }
        
        return lower == 0;
    }
};

