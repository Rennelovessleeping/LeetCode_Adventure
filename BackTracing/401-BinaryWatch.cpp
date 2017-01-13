/**************************************************************************
 * File Name : 401-BinaryWatch.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-01-2017
 *
 * Last Modified : Fri Jan 13 13:45:29 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Bit Manipulation
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
        vector<string> ans;
        if (num > 8) return ans;
        
        for(int hour=0; hour<12; hour++){
            for(int minute=0; minute<60; minute++){
                if(bitset<10>(hour<<6 | minute).count() == num ){
                    ans.push_back(to_string(hour) + (minute<10 ? ":0" : ":") + to_string(minute));
                }
            }
        }
        
        return ans;
    }
};

// Back_tracing
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num > 8) return ans;
        helper(make_pair(0, 0), num, 0);
        return ans;
    }
    
private:
    vector<string> ans;
    vector<int> hour{1, 2, 4, 8};
    vector<int> minute{1, 2, 4, 8, 16, 32};
    
    void helper(pair<int, int> time, int num, int used){
        if(num == 0){ // Only when num are used up, the time will be stored.
            ans.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
            return;
        }
        for(int i=used;i<hour.size()+minute.size();i++){
            if(i<hour.size()){
                time.first += hour[i];
                if(time.first<12) helper(time, num-1, i+1);
                time.first -= hour[i]; // backtracing
            }
            else{
                time.second += minute[i-hour.size()];
                if(time.second<60) helper(time, num-1, i+1);
                time.second -= minute[i-hour.size()]; // backtracing
            }
        }
    }
    
};
