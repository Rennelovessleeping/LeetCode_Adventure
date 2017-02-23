/**************************************************************************
 * File Name : 68-TextJustification.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-02-2017
 *
 * Last Modified : Thu Feb 23 12:13:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use the modulo trick the distribute more spaces on the left slots than the right ones
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i=0, n, len; i<words.size(); i+=n){
            for(n = 0, len = 0; i+n < words.size() && len+words[i+n].size() <= maxWidth-n; n++){
                len += words[i+n].size();
            }
            string tmp = words[i];
            for(int j=0; j<n-1; j++){
                if(i+n >= words.size()) tmp += " "; // When n==1 or 0;
                else{
                    tmp += string( (maxWidth-len)/(n-1) + (j < (maxWidth-len)%(n-1)), ' ');
                }
                tmp += words[i+j+1];
            }
            
            tmp += string(maxWidth-tmp.size(), ' ');
            res.push_back(tmp);
        }
        
        return res;
    }
};
