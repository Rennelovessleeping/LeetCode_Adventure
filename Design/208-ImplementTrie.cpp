/**************************************************************************
 * File Name : 28-ImplementTrie.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 21:18:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class TrieNode{
public:
    TrieNode* next[26]; // store the 26 possibilities for the following char 
    bool isWord;
    TrieNode(bool b=false){
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    TrieNode* root; 
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(int i=0; i<word.size(); i++){
            if(p->next[word[i]-'a'] == nullptr){
                p->next[word[i]-'a'] = new TrieNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->isWord;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    
private:
    
    TrieNode* find(string key){
        TrieNode *p = root;
        for(int i=0; i<key.size() && p!=nullptr; i++){
            p = p->next[key[i]-'a'];
        }
        return p;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
