/**************************************************************************
 * File Name : 676-ImplementMagicDictionary.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-09-2017
 *
 * Last Modified : Sat Sep 16 15:00:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Hash table solution for small size dict
class MagicDictionary {
public:
    unordered_map<string, vector<pair<int, char>>> mp;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word:dict) {
            for(int i=0; i<word.length(); i++) {
                string key = word.substr(0,i) + word.substr(i+1);
                mp[key].push_back({i, word[i]});
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i=0; i<word.size(); i++) {
            string key = word.substr(0,i) + word.substr(i+1);
            if(mp.count(key)) {
                for(auto tmp:mp[key]) {
                    if(i == tmp.first && word[i] != tmp.second) return true;
                }
            }
        }
        return false;
    }
};

// Trie Solution
class MagicDictionary {
public:
    struct TrieNode {
        bool isWord;
        TrieNode* next[26];
        TrieNode():isWord(false) {
            fill_n(next, 26, nullptr);
        };
    };
    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word:dict) {
            TrieNode *p = root;
            for(auto ch:word) {
                if(p->next[ch-'a'] == nullptr) p->next[ch-'a'] = new TrieNode();
                p = p->next[ch-'a'];
            }
            p->isWord = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
    bool dfs(TrieNode* root, string word, int change) {
        // pass number of changes to help check whether there is a word in dict that is if and only if different from the given word by one char 
        if(!root || (!root->isWord && word.empty()) || change > 1) return false;
        else if(root->isWord && word.empty()) return change == 1;
        
        for(int i=0; i<26; i++) {
            if(root->next[i] == nullptr) continue;
            if(i == word[0]-'a') {
                if(dfs(root->next[i], word.substr(1), change)) return true;
            }
            else {
                if(dfs(root->next[i], word.substr(1), change+1)) return true;
            }
        }
        
        return false;
    }
};
