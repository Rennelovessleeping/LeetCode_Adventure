/**************************************************************************
 * File Name : 273-IntegerToEnglishWords.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-02-2017
 *
 * Last Modified : Thu Feb  9 23:46:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        string res = int_string(num);
        return res.substr(1);
    }

private:
    unordered_map<int, string> num2string {
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4,"Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
        {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, 
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, 
        {90, "Ninety"}
    };
    
    string int_string(int n) {
        if (n >= 1000000000) return int_string(n/1000000000) + " Billion" + int_string(n - 1000000000*(n/1000000000));
        else if (n >= 1000000) return int_string(n/1000000) + " Million" + int_string(n - 1000000*(n/1000000));
        else if (n >= 1000) return int_string(n/1000) + " Thousand" + int_string(n-1000*(n/1000));
        else if (n >= 100) return int_string(n/100) + " Hundred" + int_string(n-100*(n/100));
        else if (n >= 20) return " " + num2string[(n/10)*10] +  int_string(n%10);
        else if (n >=1 ) return " " + num2string[n];
        else return "";
    }
    
};
