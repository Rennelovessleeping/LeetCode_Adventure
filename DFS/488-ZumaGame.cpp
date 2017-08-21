/**************************************************************************
 * File Name : 488-ZumaGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-05-2017
 *
 * Last Modified : Sat May  6 12:18:10 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxCount = 6;
    int findMinStep(string board, string hand) {
        
        unordered_map<char, int> mp;
        for(const auto& ch:hand) mp[ch]++;
        
        int res = dfs(board+'#', mp); // make up a dummpy end for ease of removing consecutive balls
        
        return res == maxCount ? -1 : res;
    }
    
    int dfs(string board, unordered_map<char, int>& mp) {
        board = removeConsecutive(board); // remove all the consecutive balls due to the last hit
        if( board == "#") return 0;
        
        int res = maxCount;
        for(int left=0, right=0; right<board.size(); right++) {
            if(board[right] == board[left]) continue;
            int need = 3 - (right-left);
            if(mp[board[left]] >= need) {
                mp[board[left]] -= need;
                res = min(res, need + dfs(board.substr(0,left) + board.substr(right), mp));
                mp[board[left]] += need;
            }
            left = right;
        }
        return res;
    }
    
    
    string removeConsecutive(string board){
        for(int left=0, right=0; right<board.size(); right++){
            if(board[right] == board[left]) continue;
            if(right-left >= 3) return removeConsecutive(board.substr(0,left) + board.substr(right));
            left = right;
        }
        return board;
    }
};
