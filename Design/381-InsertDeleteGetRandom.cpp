/**************************************************************************
 * File Name : 381-InsertDeleteGetRandom.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-02-2017
 *
 * Last Modified : Fri Feb 24 10:44:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use two hash tables that are mutually indexed
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = mp.find(val) == mp.end();
        mp[val].push_back(nums.size());
        nums.push_back({val, mp[val].size()-1});
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res = mp.find(val) != mp.end();
        if(res) {
            mp[nums.back().first][nums.back().second] = mp[val].back();
            swap(nums.back(), nums[mp[val].back()]);
            nums.pop_back();
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);
        }
        
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()].first;
    }
    
private:
    unordered_map<int, vector<int>> mp; //{val, idx in nums}
    vector<pair<int, int>> nums; //{val, idx in mp[val]} for removal purpose
    
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
