/**************************************************************************
 * File Name : 432-AllO1DataStructure.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-09-2017
 *
 * Last Modified : Thu Sep  7 17:18:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // need to change mp[key]
        // if key does exist, add a 0-value row to shorten the code
        if(mp.find(key) == mp.end()) mp[key] = buckets.insert(buckets.begin(), Bucket{0, {key}}); 
        
        auto next = mp[key], cur = next++;
        if(next == buckets.end() || next->val > cur->val+1) {
            next = buckets.insert(next, {cur->val+1, {}});
        }
        next->keys.insert(key);
        mp[key] = next;
        
        cur->keys.erase(key);
        if(cur->keys.empty()) buckets.erase(cur);
            
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // might earse key from m when key's value == 1
        if(mp.find(key) == mp.end()) return;
        
        auto prev = mp[key], cur = prev--;
        mp.erase(key);
        if(cur->val > 1) {
            if(cur == buckets.begin() || prev->val < cur->val-1) {
                prev = buckets.insert(cur, Bucket{cur->val-1, {}});
            }
            prev->keys.insert(key);
            mp[key] = prev;
        }        
        
        cur->keys.erase(key);
        if(cur->keys.empty()) buckets.erase(cur);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
    
private:
    struct Bucket{
        int val;
        unordered_set<string> keys;
    };
    
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> mp; // {key, itr pointing to the bucket key is in}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
