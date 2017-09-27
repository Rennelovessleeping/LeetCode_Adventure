/**************************************************************************
 * File Name : 301-RemoveInvalidParenthses.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-02-2017
 *
 * Last Modified : Mon Sep 25 16:00:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        helper(res, s, 0, 0, "()");
        return res;
    }

private:
    void helper(vector<string>& res, string s, int preLeft, int preRight, string par){
        for(int i=preLeft, counter=0;i<s.size();i++){
            if(s[i] == par[0]) counter++;
            if(s[i] == par[1]) counter--;
            if(counter>=0) continue;
            // When finding extra par[1]:")"
            for(int j=preRight; j<=i;j++){
                if(s[j] == par[1] && (j==preRight || s[j-1]!=par[1])) 
                    helper(res, s.substr(0, j) + s.substr(j+1), i, j, par);
            }
            return; // All extra ")" and "(" has already been found; 
        }
        
		// When finishing the for loop. current string s must not have extra ')' and thus start over to find out all '('
        string reversed_s(s.rbegin(), s.rend());  
        if(par[1] == ')'){
            helper(res, reversed_s, 0, 0, ")("); // Back to the top level of recursion
        }
        else{
            res.push_back(reversed_s);
        }
    }
};

// A simpler version of this problem requires us to return only one valid string;
// In that case, we only need to remove extra '(' and ')' only once;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // remove extra '('
        string res;
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            
            if(cnt >= 0) res += s[i];
            else cnt = 0;
        }
        
        s = res;
        res = "";
        cnt = 0;
        // remove extra ')'
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')') cnt++;
            else if(s[i] == '(') cnt--;
            
            if(cnt >= 0) res = s[i] + res;
            else cnt = 0;
        }
        
        return vector<string> {res};
    }
};

