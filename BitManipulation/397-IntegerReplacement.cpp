/**************************************************************************
 * File Name : 397-IntegerReplacement.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-02-2017
 *
 * Last Modified : Tue Feb  7 00:34:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
class Solution {
public:
    int integerReplacement(int n) {
        
        unordered_set<long> checked;
        queue<pair<long, int>> q;
        q.push(make_pair(n, 0));
        
        while(!q.empty()){
            pair<long, int> t = q.front();
            q.pop();

            if(t.first == 1) return t.second;
            checked.insert(t.first);
            
            if((t.first-1)&1 && checked.find(t.first/2) == checked.end()) q.push(make_pair(t.first/2, t.second+1));
            if(checked.find(t.first-1) == checked.end()) q.push(make_pair(t.first-1, t.second+1));
            if(checked.find(t.first+1) == checked.end()) q.push(make_pair(t.first+1, t.second+1));
        }
        
        return 0;
    }
};

// Use bit manipulation
class Solution {
public:
    int integerReplacement(int n) {
        
        if (n == INT_MAX) return 32;
        if (n == 1) return 0;
        if (n == 3) return 2;
        
        if (n&1) return n%4 == 3 ? 1 + integerReplacement(n+1) : 1 + integerReplacement(n-1);
        // n%4 == 3(11) do n+1; n%4 == 1(01) do n-1;
        
        return 1 + integerReplacement(n/2);
    }
};;
