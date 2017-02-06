/**************************************************************************
 * File Name : 150-EvaluateReversePolishNotation.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 17:55:49 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //if(tokens.size()==0) return -1;
        stack<string> res;
        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int op1 = string2num(res.top());
                res.pop();
                int op2 = string2num(res.top());
                res.pop();
                
                if(tokens[i] == "+") res.push(to_string(op2+op1));
                else if(tokens[i] == "-") res.push(to_string(op2-op1));
                else if(tokens[i] == "*") res.push(to_string(op2*op1));
                else  res.push(to_string(op2/op1));
                
            }
            else res.push(tokens[i]);
            
        }
        
        return string2num(res.top());
        
    }
    
private:
    int string2num(string t){
        int num = 0, sign = 1;
        
        if(t[0] == '-') {t.erase(0,1); sign = -1;}
        for(auto it = t.begin(); it!=t.end(); it++){
            num = num*10 + *it -'0';
        }
        
        return sign*num;
    }
};


