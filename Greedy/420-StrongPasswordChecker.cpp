/**************************************************************************
 * File Name : 420-StrongPasswordChecker.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-05-2017
 *
 * Last Modified : Thu May  4 15:54:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int strongPasswordChecker(string s) {

        int deleteTarget = max((int) s.size() - 20,0), addTarget = max(6 - (int) s.size(),0);
        int needUpper = 1, needLower = 1, needDigit = 1;
        int toAdd = 0, toDelete = 0, toReplace = 0;
        
        // when s.size() <= 20 
        for(int l=0, r=0; r < s.length(); r++) {
            if(isupper(s[r])) needUpper = 0;
            if(islower(s[r])) needLower = 0;
            if(isdigit(s[r])) needDigit = 0;
            
            if(r-l == 2) {
                if(s[l] == s[l+1] && s[l+1] == s[r]) {
                    if(toAdd < addTarget) {
                        toAdd++; // insert at r
                        l = r;
                    }
                    else {
                        toReplace++;
                        l = r+1; // cuz r'th char will be replaced;
                    }
                }
                else l++;
            }
        }
        
        if(s.size() <= 20) return max(addTarget + toReplace, needUpper + needLower + needDigit);
        
        // when s.size() > 20: the idea is to use up the deleteTarget to make up for the change
        
        toReplace = 0;
        vector<unordered_map<int, int>> lenCnts(3); // lenCnts[len%3][len] = cnt
        for(int l=0, r=0; r <= s.length(); r++) {
            if(r == s.length() || s[l] != s[r]) {
                if(r - l > 2) lenCnts[(r-l)%3][r-l]++;
                l = r;
            }
        }
        
        for(int remLen = 0, letters_to_delete, dec; remLen < 3; remLen++) {
            for(auto& item:lenCnts[remLen]) {
                if(remLen < 2) {
                    letters_to_delete = remLen + 1;
                    dec = min(item.second, (deleteTarget - toDelete)/letters_to_delete); // # of repetitions to delete from
                    toDelete += dec*letters_to_delete;
                    item.second -= dec; // These repetitions no longer has the original length
                    
                    if(item.first - letters_to_delete > 2) lenCnts[2][item.first - letters_to_delete] += dec;
                }
                
                toReplace += (item.second) * (item.first/3);
            }
        }
        
        
        // toDelete record the deletion from repetitions that has lenght such that : len%3 == 1 or len%3 == 0
        // toReplace record the number of replacement to break all the repetitions;
        int dec = (deleteTarget - toDelete)/3;
        toReplace -= dec;
        
        return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
        
    }
};
