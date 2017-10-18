/**************************************************************************
 * File Name : PythonIndentation.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 16:07:23 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class PythonValidation {
public:
    bool valid_python_indentation(vector<string>& inputs) {
        stack<string> stk; // storing indentation levels;
        for(auto line:inputs) {
            int level = getIndent(line);
            if(stk.empty()) {
                if(level != 0) return false;
            }
            else if(stk.top().back() == ':') {// check whether is control statement
                int last_level = getIndent(stk.top());
                if(level != last_level+1) return false;
            }
            else {
                while(!stk.empty() && getIndent(stk.top()) > level) stk.pop();

                if(getIndent(stk.top()) != level) return false;
            }

            stk.push(line);
        }

        return true;

    }

    int getIndent(const string& line) {
        return line.find_first_not_of(' ')/4;
    }
};

int main(){
    vector<string> inputs = {
        "def:",
        "    abs:",
        "        b2c:",
        "            cc",
        "        bcc",
        "    b5c",
        "b6c"
    };

    PythonValidation test;
    if(test.valid_python_indentation(inputs)) cout << "Yes" << endl;
    else cout << "NO" << endl;

    return 0;
}
