/**************************************************************************
 * File Name : 642-DesignSearchAutoCompleteSystem.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-09-2017
 *
 * Last Modified : Sat Sep  9 17:24:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class AutocompleteSystem {
private:
    string prefix;
public:
    struct TrieNode{
        bool isWord;
        string str;
        int cnt;
        unordered_map<char, TrieNode*> children;
        // unordered_map<string, int> cnt; // {string starting with prefix: count};
        TrieNode(): isWord(false), str(""), cnt(0) {}
    };
    
    TrieNode *root;
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        prefix = "";
        root = new TrieNode();
        for(int i=0; i<sentences.size(); i++) insert(sentences[i], times[i]);
    }
    ~AutocompleteSystem() {
        delete root;
    }
    
    struct cmp {
        bool operator() (const pair<string, int>& l, const pair<string, int>& r) { 
            return l.second == r.second ? l.first > r.first : l.second < r.second;
        }
    };
    
    void dfs(TrieNode* p, priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>& pq) {
        if(p->str != "")  pq.push({p->str, p->cnt});
        for(auto child:p->children) dfs(child.second, pq); 
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            insert(prefix, 1);
            prefix = "";
            return vector<string>{};
        }
        
        prefix += c;
        TrieNode *p = root;
        for(auto ch:prefix) {
            if(p->children.count(ch) == 0) return vector<string> {};
            p = p->children[ch];
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        dfs(p, pq);
        
        vector<string> res;
        for(int i=0; i<3 && !pq.empty(); i++) {
            res.push_back(pq.top().first); pq.pop();
        }
        
        return res;

    }
    
    void insert(string sentence, int count) {
        TrieNode *p = root;
        for(auto ch:sentence) {
            if(!p->children.count(ch)) p->children[ch] = new TrieNode();
            p = p->children[ch];
        }
        p->str = sentence;;
        p->cnt += count;
        p->isWord = true;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

// Put a unorderd_map<string, count> is not efficient concerning memory
class AutocompleteSystem {
private:
    string prefix;
public:
    struct TrieNode{
        bool isWord;
        unordered_map<char, TrieNode*> children;
        unordered_map<string, int> cnt; // {string starting with prefix: count};
        TrieNode(): isWord(false) {}
    };
    
    TrieNode *root;
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        prefix = "";
        root = new TrieNode();
        for(int i=0; i<sentences.size(); i++) insert(sentences[i], times[i]);
    }
    ~AutocompleteSystem() {
        delete root;
    }
    
    struct cmp {
        bool operator() (const pair<string, int>& l, const pair<string, int>& r) { 
            return l.second == r.second ? l.first > r.first : l.second < r.second;
        }
    };
    
    vector<string> input(char c) {
        if(c == '#') {
            insert(prefix, 1);
            prefix = "";
            return vector<string>{};
        }
        
        prefix += c;
        TrieNode *p = root;
        for(auto ch:prefix) {
            if(p->children.count(ch) == 0) return vector<string> {};
            p = p->children[ch];
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
 
        for(auto& item:p->cnt) {
            pq.push({item.first, item.second});
        }
        
        vector<string> res;
        for(int i=0; i<3 && !pq.empty(); i++) {
            res.push_back(pq.top().first); pq.pop();
        }
        
        return res;

    }
    
    void insert(string sentence, int count) {
        TrieNode *p = root;
        for(auto ch:sentence) {
            if(!p->children.count(ch)) p->children[ch] = new TrieNode();
            p = p->children[ch];
            p->cnt[sentence] += count;
        }
        p->isWord = true;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
