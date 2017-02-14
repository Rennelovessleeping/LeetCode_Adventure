/**************************************************************************
 * File Name : 146-LRU.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-02-2017
 *
 * Last Modified : Mon Feb 13 23:07:42 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// hashtable + list: insertion in list is const time operatoin; thus using it to main the sequence of lastest touch cache is smart.
class LRUCache {
public:
    LRUCache(int capacity) :cap(capacity) {}
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        touch(key);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) touch(key);
        else{
            if(mp.size()==cap){
                mp.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        mp[key] = {value, used.begin()};
    }
    
private:
    unordered_map<int, pair<int, list<int>::iterator>> mp; // store [key,[value, iterator point to key in used list]] pair
    list<int> used; // squence of used cache keys sorted by how recent they were used;
    int cap;
    
    void touch(int key){
        used.erase(mp[key].second);
        used.push_front(key);
        mp[key].second = used.begin();
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

