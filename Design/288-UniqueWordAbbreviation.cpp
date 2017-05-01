/**************************************************************************
 * File Name : 288-UniqueWordAbbreviation.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 12:43:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> mp; // {abbr:cnt}

    ValidWordAbbr(vector<string> dictionary) {
        for(auto word:dictionary) {
            mp[Abbr(word)].insert(word);
        }
    }

    bool isUnique(string word) {
        string tmp = Abbr(word);
        return mp[tmp].count(word) == mp[tmp].size();
    }

    string Abbr(const string& word) {
        int n = word.size();
        if(n <= 2) return word;
        else return word[0] + to_string(n-2) + word.back();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
