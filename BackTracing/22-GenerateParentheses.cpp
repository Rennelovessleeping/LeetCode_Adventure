/**************************************************************************
 * File Name : 22-GenerateParentheses.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 15:04:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Raw backtracing solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return vector<string>();
        vector<string> ans={"()"};
        
        for(int i=1;i<n;i++){
            vector<string> tmp;
            string newPattern;
            for(int j=0;j<ans.size();j++){
                newPattern = "()" + ans[j];
                if( find(tmp.begin(), tmp.end(), newPattern) == tmp.end() ) tmp.push_back(newPattern);
                newPattern = ans[j] + "()";
                if( find(tmp.begin(), tmp.end(), newPattern) == tmp.end() ) tmp.push_back(newPattern);
                
                for(int k=1;k<ans[j].size();k++){
                    string curPair(ans[j].begin()+k-1, ans[j].begin()+k+1);
                    if( curPair.compare("()") == 0 || curPair.compare(")(") == 0 || curPair.compare("((") == 0 ||curPair.compare("))") == 0){
                        newPattern = string (ans[j].begin(), ans[j].begin()+k) + "()"
                                    + string (ans[j].begin()+k, ans[j].end());
                        if( find(tmp.begin(), tmp.end(), newPattern) == tmp.end() ) tmp.push_back(newPattern);
                    }
                    
                }
            }
            ans.swap(tmp);
        }
        return ans;
    }
};

// Recursive solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        addPar(ans, "", n, 0);
        return ans;
    }
    
    void addPar(vector<string> &v, string str, int left, int right){
        if(left==0 && right ==0){ v.push_back(str); return; }
        
        if(right>0) addPar(v, str+")", left, right-1);
        if(left>0) addPar(v, str+"(", left-1, right+1);
        
    }
};
