class Solution {
public:
    bool checkValidString(string s) {
        if (s.empty() || s == "*") return true;
        
        stack<char> stk;
        int extra = 0, star = 0;
        for(int i=0, j=0; i<s.size(); i=j+1, j=i) {
            while(j < s.size() && s[j] != '*') j++;
            extra += calc_extra(s.substr(i, j-i));
            if(j < s.size()) extra--;
        }
        
        return extra <= 0;
    }
    
    int calc_extra(string s) {
        stack<char> stk;
        for(auto ch:s) {
            if(ch == '(') stk.push(')');   
            else {
                if(stk.empty() || stk.top() != '(') stk.push(')');
                else stk.pop();
            }
        }
        return stk.size();
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        return dfs(s, vector<char> {});
    }
    
    bool dfs(string s, vector<char> stk) {
        if(s.empty() && stk.empty()) return true;
        
        for(int i=0; i<s.size(); i++) {
            if (s[i] != '*') {
                if(s[i] == '(') stk.push_back('(');
                else{
                    if(!s.empty() && stk.back() == '(') stk.pop_back();
                    else stk.push_back(')');
                }
            }
            else {
                return (dfs(s.substr(1), stk) || dfs('(' + s.substr(1), stk) || dfs(')' + s.substr(1), stk)) ;
            }
        }
        
        return stk.empty();
    }
};

class Solution {
    char[] ops = new char[]{'+','-','*','/'};
    
    public boolean judgePoint24(int[] nums) {
        List<Double> list = new ArrayList<>();
        for (int num: nums)
            list.add(1.0 * num);
        
        return search(list);
    }
    
    private boolean search(List<Double> list){
        if (list.size()==1){
            return list.get(0)==24.0;
        }
        
        List<Double> tmp = new ArrayList<>();
        for (int i=0; i<list.size(); i++)
            for (int j=0; j<list.size(); j++)
                if (i!=j){
                    for (char op: ops){
                        if ((op=='+' || op=='*') && (i>j)) continue;
                        if (op=='/' && list.get(j)==0.0) continue;
                        double res = 0.0;
                        switch(op){
                            case '+': res = list.get(i) + list.get(j);
                                      break;
                            case '-': res = list.get(i) - list.get(j);
                                      break;
                            case '*': res = list.get(i) * list.get(j);
                                      break;
                            case '/': res = list.get(i) / list.get(j);
                                      break;
                        }
                        
                        tmp.clear();
                        tmp.add(res);
                        for (int k=0;k<list.size();k++)
                            if (k!=i && k!=j)
                                tmp.add(list.get(k));
                        
                        boolean tmpRes = search(tmp);
                        if (tmpRes)
                            return true;
                    }
                }
        
        return false;
    }
}

class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<ch> digits;
        for(auto ch:time) {
            if(ch == ":") continue;
            digits.insert(ch);
        }
        string res;
        dfs(res, 0);
        return res;
    }
    
    void dfs(unordered_set<ch>& digits, string& res, int pos, string path, string target) {
        if(pos == 2) {
            if(stoi(path) > 24) return;
            path += ":";
            pos++;
        }
        else if (pos == 5) {
            if(stoi(path.substr(3)) > 60 || dist(target, path) >= dist(target, res)) return;
            res = path;
        }
        for() {
            
        }
    }
    
    int dist(string target, string time){
        int tmp1 = stoi(target.substr(0,2)) * 60 + stoi(target.substr(3));
        int tmp2 = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
        return min(1440-abs(tmp1-tmp2), abs(tmp1-tmp2));
    }
};
