/**************************************************************************
 * File Name : 621-TaskScheduler.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-06-2017
 *
 * Last Modified : Fri Jun 23 13:57:17 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) solution: the key idea is to estimate the size of frames where the most frequent tasks are separated at least by n chars.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> count(26,0);
        for(char t:tasks) count[t-'A']++;
        sort(count.begin(), count.end());
        
        int mostFreq = 25;
        while(mostFreq >= 0 && count[mostFreq] == count.back()) mostFreq--;
        
        return max((int)tasks.size(), (n+1) * (count.back()-1) + 25-mostFreq);
    }
};

// One can also naively use a priority queue to simulate a task scheduling process
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;
        for(auto t:tasks) mp[t]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto item:mp) pq.push({item.second, item.first});
        
        int res = 0;
        int k = n+1; // no repeating tasks can appear in the same block
        while(!pq.empty()) {
            int blocktime = 0;
            vector<pair<int, char>> tmp;
            
            // schedule the top k frequent tasks
            for(int i=0; i<k && !pq.empty(); i++){
                auto top = pq.top(); pq.pop();
                tmp.push_back({top.first-1, top.second});
                blocktime++;
            }
            
            for(auto t:tmp) {
                if(t.first) pq.push(t);
            }
            
			// When there is no more task to schedule, dont add the whole block size!!!
            res += !pq.empty() ? k : blocktime;
        }
        
        return res;
    }
};
