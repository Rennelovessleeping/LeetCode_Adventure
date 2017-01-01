/**************************************************************************
 * File Name : 464-CanIWin.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-01-2017
 *
 * Last Modified : Sun Jan  1 16:14:37 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution: current desiredTotal represents depth
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if (desiredTotal <= 0) return true;
        if (desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2) return false;
        
        vector<unordered_map<int,bool>> stateHashTable(desiredTotal);
        int key = (1 << maxChoosableInteger) - 1; // Initial state: no numbers used
        
        return helper(key, desiredTotal, maxChoosableInteger, stateHashTable);
        
    }
    
    bool helper(int key, int desiredTotal, int maxInt, vector<unordered_map<int,bool>>& stateHashTable ){
        
        if( stateHashTable[desiredTotal-1].find(key) !=  stateHashTable[desiredTotal-1].end() ) 
            return stateHashTable[desiredTotal-1][key];
        
        for(int i=maxInt-1; i>=0;i--){
            if(key & (1 << i)) { //when ith integer is unused
                key ^= (1 << i); //Use ith integer
                if(i+1 >= desiredTotal || !helper(key, desiredTotal-(i+1), maxInt, stateHashTable) ){
					key |= (1<<i);
                    return(stateHashTable[desiredTotal-1][key] = true);
                }
                key |= (1<<i);
            }
            
        }
        return(stateHashTable[desiredTotal-1][key] = false);
        
    }
    
};

// optimized DP solution
class Solution {
public:
    unordered_map<int,bool> stateHashTable;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        if (desiredTotal <= 0) return true;
        if (desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2) return false;
        
        int key = (1 << maxChoosableInteger) - 1; // Initial state: no numbers used
        return helper(key, desiredTotal, maxChoosableInteger);
        
    }
    
    bool helper(int key, int desiredTotal, int maxInt){
        
        if( stateHashTable.find(key) !=  stateHashTable.end() ) 
            return stateHashTable[key];
        
        for(int i=maxInt-1; i>=0;i--){
            if(key & (1 << i)) { //when ith integer is unused
                key ^= (1 << i); //Use ith integer
                if(i+1 >= desiredTotal || !helper(key, desiredTotal-(i+1), maxInt) ){
                    key |= (1<<i); 
                    stateHashTable[key] = true;
                    return true;
                }
                key |= (1<<i);
            }
            
        }
        stateHashTable[key] = false;
        return false;
        
    }
    
};
