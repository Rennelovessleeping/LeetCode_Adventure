/**************************************************************************
 * File Name : 631-DesignExcelFormula.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-09-2017
 *
 * Last Modified : Wed Sep  6 23:13:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Excel {
public:
    Excel(int H, char W) {
        Exl = vector<vector<int>> (H+1, vector<int>(W-'A'+1, 0));
    }
    
    void set(int r, char c, int v) {
        update(r, c, v);        
        int key = r*26 + c-'A';
        if(bward.count(key)){
            for(int tmp:bward[key]) fward[tmp].erase(key);
            bward[key].clear();
        }
    }
    
    int get(int r, char c) {
        return Exl[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int key = r*26 + c-'A';
        if(bward.count(key)){
            for(int tmp:bward[key]) fward[tmp].erase(key);
            bward[key].clear();
        }
        
        int res = 0;
        for(auto str:strs) {
            int sep = str.find(':'), left, right, top, bottom;
            if(sep == -1) {
                left = right = str[0]-'A';
                top = bottom = stoi(str.substr(1));
            }
            else {
                left = str[0]-'A', top = stoi(str.substr(1,sep-1));
                right = str[sep+1]-'A', bottom = stoi(str.substr(sep+2));
            }
            
            for(int i=top; i<=bottom; i++) {
                for(int j=left; j<=right; j++) {
                    res += Exl[i][j];
                    fward[i*26+j][key]++;
                    bward[key].insert(i*26+j);
                }
            }
        }
        
        update(r, c, res);
        return res;
    }
    
    void update(int r, char c, int v) {
        
        queue<pair<int, int>> q; //{fward cell:diff};
        q.push({r*26 + c - 'A', v-Exl[r][c-'A']}); 
        Exl[r][c-'A'] = v;
        
        while(!q.empty()){
            int key = q.front().first, diff = q.front().second;
            q.pop();
            if(fward.count(key) == 0) continue;
            for(auto it = fward[key].begin(); it != fward[key].end(); it++) {
                int k = it->first;
                q.push({k, diff*(it->second)});
                Exl[k/26][k%26] += diff*(it->second);
            }
        }
    }
    
private:
    vector<vector<int>> Exl;
    unordered_map<int, unordered_map<int, int>> fward;
    unordered_map<int, unordered_set<int>> bward;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
