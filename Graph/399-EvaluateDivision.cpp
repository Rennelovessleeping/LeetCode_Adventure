/**************************************************************************
 * File Name : 399-EvaluateDivision.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 18:32:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> mp; // mp[dividend][divisor] = dividend/divisor;
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        
        for(int i=0; i < equations.size(); i++) {
            mp[equations[i].first][equations[i].second] = values[i];
            if(values[i]) mp[equations[i].second][equations[i].first] = 1.0/values[i];
        }
        
        
        vector<double> res;
        
        for(auto q:queries) {
            unordered_set<string> visited;
            double tmp = search(q.first, q.second, visited);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1.0);
        }
        
        return res;
    }
    
    double search(string dividend, string divisor, unordered_set<string>& visited) {
        if(mp[dividend].find(divisor) != mp[dividend].end()) return mp[dividend][divisor];
        
        for(auto d : mp[dividend]) {
            if(visited.find(d.first) == visited.end()) {
                visited.insert(d.first);
                double tmp = search(d.first, divisor, visited);
                if(tmp) return tmp*d.second;
            }
        }
        
        return 0;
    }
};
