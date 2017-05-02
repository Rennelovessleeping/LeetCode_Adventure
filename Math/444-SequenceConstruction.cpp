/**************************************************************************
 * File Name : 444-SequenceConstruction.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 22:44:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, unordered_set<int>> mp; // {parent:child}
        unordered_map<int, int> indegree; // {node:indegree};
        
        // construct graph can calculate indegree
        for(const auto& seq:seqs){
            int len = seq.size();
            
            if(len == 1) {
                if(mp.find(seq[0]) == mp.end()) {
                    mp[seq[0]] = unordered_set<int> {};
                    indegree[seq[0]] = 0;
                }
            }
            
            else {
                for(int i=0; i<len-1; i++) {
                    if(mp.find(seq[i]) == mp.end()) {
                        mp[seq[i]] = unordered_set<int> {};
                        indegree[seq[i]] = 0;
                    }
                    if(mp.find(seq[i+1]) == mp.end()) {
                        mp[seq[i+1]] =  unordered_set<int> {};
                        indegree[seq[i+1]] = 0;
                    }
                    
                    if(mp[seq[i]].insert(seq[i+1]).second) indegree[seq[i+1]]++; // avoid duplicate edges
                }
            }
            
        }
        
        queue<int> q;
        for(auto item:indegree) {
            cout << item.first << ", " << item.second << endl;
            if(item.second == 0) q.push(item.first);
        }
        
        int idx = 0;
        while(!q.empty()) {
            int len = q.size();
            if(len > 1) return false; // return false when there is more than 1 path;
            int tmp = q.front(); q.pop();
            if(idx == org.size() || tmp != org[idx++]) return false; // return false when the graph doesnt follow seq of org
            for(int next:mp[tmp]){
                if(--indegree[next] == 0) q.push(next);
            }
        }
        
        return idx == org.size() && idx == mp.size();
        // idx == org.size() to check whether the graph construct the full org sequence;
        // idx == mp.size() to check whether seqs contains more nodes than org

    }
};
