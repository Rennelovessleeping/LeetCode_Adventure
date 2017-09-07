/**************************************************************************
 * File Name : 588-DesignInMemoryFileSystem.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-09-2017
 *
 * Last Modified : Wed Sep  6 23:41:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class FileSystem {
public:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode*> children;
        TrieNode(): isFile(false), content("") {}
    };
    
    TrieNode *root;
    
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> parse(string path) {
        vector<string> res;
    
        for(int i=1, j=1; j<=path.size(); ++j) {
            // rule out consecutive slash e.g. "//" or single "/"
            if(i!=j && (j == path.size() || path[j] == '/')) {
                res.push_back(path.substr(i,j-i));
                i = j+1;
            }
        }
        
        // cout << path << ": ";
        // for(auto dir:res) cout << dir << ", "; cout << endl;
        return res;
    }
        
    vector<string> ls(string path) {
        vector<string> dirs = parse(path);
        
        TrieNode *cur = root;
        for(auto dir:dirs) cur = cur->children[dir];
        if(cur->isFile) return {dirs.back()};
        
        vector<string> res;
        for(auto& item:cur->children) res.push_back(item.first);
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        vector<string> dirs = parse(path);
        TrieNode *cur = root;
        for(auto dir:dirs) {
            if(cur->children.find(dir) == cur->children.end()) cur->children[dir] = new TrieNode();
            cur = cur->children[dir];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> dirs = parse(filePath);
        TrieNode *cur = root;
        for(auto dir:dirs) {
            if(cur->children.find(dir) == cur->children.end()) cur->children[dir] = new TrieNode();
            cur = cur->children[dir];
        }
        
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> dirs = parse(filePath);
        TrieNode *cur = root;
        for(auto dir:dirs) {
            if(cur->children.find(dir) == cur->children.end()) cur->children[dir] = new TrieNode();
            cur = cur->children[dir];
        }
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
