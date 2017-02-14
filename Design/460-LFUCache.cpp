/**************************************************************************
 * File Name : 460-LFUCache.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-02-2017
 *
 * Last Modified : Mon Feb 13 23:55:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// 3 hash table solution
class LFUCache {
public:
    LFUCache(int capacity):cap(capacity) {
        minFreq = 0;
    }
    
    int get(int key) {
        if(cap<=0 || mp.find(key) == mp.end()) return -1;
        touch(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        if(mp.find(key) != mp.end()){
            mp[key].first = value;
            touch(key);
            return;
        }
        
        if(mp.size() >= cap){
            mp.erase(freqCnt[minFreq].front());
            mpIter.erase(freqCnt[minFreq].front());
            freqCnt[minFreq].pop_front();
            //if(freqCnt[minFreq].size()==0) minFreq++;
        }
        mp[key] = {value, 1};
        freqCnt[1].push_back(key);
        mpIter[key] = --freqCnt[1].end();
        minFreq = 1;
        
    }
    
private:
    int cap;
    int minFreq;
    unordered_map<int, pair<int, int>> mp; //{key, {value, freq}}
    unordered_map<int, list<int>::iterator> mpIter; //{key, iter to pos in freqCnt list}
    unordered_map<int, list<int>> freqCnt; //{frequncy, key list}
    
    void touch(int key){
        freqCnt[mp[key].second].erase(mpIter[key]);
        mp[key].second++;
        freqCnt[mp[key].second].push_back(key);
        mpIter[key] = --freqCnt[mp[key].second].end();
        
        if(freqCnt[minFreq].size()==0) minFreq++;
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

