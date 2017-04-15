/**************************************************************************
 * File Name : 165-CompareVersionNumbers.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 12:57:46 2017
 *
 * Created By :  RenneBai
**************************************************************************/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        
        while(i < len1 || j < len2) {
            int num1 = 0, num2 = 0;
            while(i < len1 && version1[i] != '.') num1 = num1*10 + version1[i++] - '0';
            while(j < len2 && version2[j] != '.') num2 = num2*10 + version2[j++] - '0';
            //cout << num1 << ", " << num2 << endl;
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            
            i++; 
            j++;
        }
        
        
        return 0;
    }
};
