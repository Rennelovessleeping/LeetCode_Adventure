/**************************************************************************
 * File Name : 13-RomanToInteger.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 11:05:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> symbolTable;
        symbolTable = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
            
        };
        int num = symbolTable[s.back()];
        
        for(int i=s.size()-2;i>=0;i--){
            if(symbolTable[s[i]] < symbolTable[s[i+1]]) num -= symbolTable[s[i]];
            else num += symbolTable[s[i]];
        }
        
        return num;
        
    }
};
