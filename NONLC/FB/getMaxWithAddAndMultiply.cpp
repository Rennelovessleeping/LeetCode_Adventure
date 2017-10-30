/**************************************************************************
 * File Name : getMaxWithAddAndMultiply.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-10-2017
 *
 * Last Modified : Tue Oct 24 16:59:32 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// divide-n-conquer + memorization
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;
int getMax(string s) {
    if(mp.count(s)) return mp[s];
    int res = stoi(s);
    for(int i=1; i<s.size(); i++){
        string num1 = s.substr(0,i), num2 = s.substr(i);
        if(num1.size()>1 && num1[0] == '0' || num2.size()>1 && num2[0] == '0') continue;
        int cand1 = getMax(num1), cand2 = getMax(num2);
        res = max(res, max(cand1*cand2, cand1+cand2));
    }
    return mp[s] = res;
}

int getMax_helper(string s) {
    int res = 0;
    for(int i=1; i<s.size(); i++){
        string num1 = s.substr(0,i), num2 = s.substr(i);
        if(num1.size()>1 && num1[0] == '0' || num2.size()>1 && num2[0] == '0') continue;
        int cand1 = getMax(num1), cand2 = getMax(num2);
        res = max(res, max(cand1*cand2, cand1+cand2));
    }
    return res;
}

int main() {
    cout << getMax_helper("9") << endl;
    cout << getMax("9") << endl;
    return 0;
}
