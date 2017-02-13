/**************************************************************************
 * File Name : 211-AddAndSearchWord.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 21:42:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
ass TrieNode{
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode(): isWord(false){
        memset(next, 0, sizeof(next));
    } 
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for(int i=0; i<word.size();i++){
            if(p->next[word[i]-'a'] == nullptr){
                p->next[word[i]-'a'] = new TrieNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, root);
    }
    
private:
    bool query(string word, TrieNode *root){
        TrieNode *p = root;
        for(int i=0; i<word.size(); i++){
            if(p && word[i] !='.') p = p->next[word[i]-'a'];
            else if(p && word[i] == '.'){
                TrieNode *tmp = p;
                for(int j=0; j<26; j++){
                    p = tmp->next[j]; // keep p to be the end of search!!
                    if(query(word.substr(i+1), p)) return true;
                }
            }
            else break;
        }
        return p && p->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


