/**************************************************************************
 * File Name : 282-ExpressionAddOperators.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 18:23:17 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for(int i=1;i<=num.size();i++){
            string operand1 = num.substr(0, i);
            long int num1 = stol(operand1);
            if(to_string(num1).size()!= operand1.size()) continue;
            dfs(res, num, operand1, i, num1, num1, target);
        }
        
        return res;
    }
private:
    void dfs(vector<string>&res, const string& num, string path, int pos, long int cur, long int preOperand, int target){
        if(pos == num.size() && cur == target) {
            res.push_back(path);
            return;
        }
        
        for(int i=pos+1;i<=num.size();i++){
            string operand2 = num.substr(pos, i-pos);
            long int num2 = stol(operand2); // To avoid leading 0's
            if(to_string(num2).size()!= operand2.size()) continue;
            dfs(res, num, path+'+'+operand2, i, cur+num2, num2, target);
            dfs(res, num, path+'-'+operand2, i, cur-num2, -num2, target);
            dfs(res, num, path+'*'+operand2, i, cur-preOperand + preOperand*num2, preOperand*num2, target); // Keep recent linear operator
            // Note when the first two operands times up, cur - preOerand = 0 as we assign num2 to both of them 
			// The expression is linear, so the sign os correct as we assign preOperand in "-" case as -num2 
        }
        
    }
};

//Originial solution
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for(int i=1;i<=num.size();i++){
            string operand1 = num.substr(0, i);
            long int num1 = stol(operand1);
            if(to_string(num1).size()!= operand1.size()) continue;
            dfs(res, num, operand1, i, num1, num1, target, '*');
        }
        
        return res;
    }
private:
    void dfs(vector<string>&res, const string& num, string path, int pos, long int cur, long int preOperand, int target, char op){
        if(pos == num.size() && cur == target) {
            res.push_back(path);
            return;
        }
        
        for(int i=pos+1;i<=num.size();i++){
            string operand2 = num.substr(pos, i-pos);
            long int num2 = stol(operand2); // To avoid leading 0's
            if(to_string(num2).size()!= operand2.size()) continue;
            dfs(res, num, path+'+'+operand2, i, cur+num2, num2, target, '+');
            dfs(res, num, path+'-'+operand2, i, cur-num2, num2, target, '-');
            dfs(res, num, path+'*'+operand2, i, (op=='-') ? cur+preOperand-preOperand*num2 : ((op=='+') ? cur-preOperand + preOperand*num2 : preOperand*num2), preOperand*num2, target, op); // Keep recent linear operator
            
        }
        
    }
};


