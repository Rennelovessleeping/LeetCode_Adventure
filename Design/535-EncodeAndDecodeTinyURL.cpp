/**************************************************************************
 * File Name : 535-EncodeAndDecodeTinyURL.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 13:05:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    // The key idea is longUrl --> id/shortUrl(string reprentation of id)
    const string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> mp; // {longurl: shorturl}
    unordered_map<int, string> db; // {id in database: longurl}
    int id = 0;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(mp.find(longUrl) != mp.end()) return mp[longUrl];
        string res="";
        int count = ++id;
        
        while(count > 0) {
            res = dict[count%62] + res;
            count /= 62;
        }
        
        while(res.size() < 6) res = "0" + res;
        mp[longUrl] = res;
        db[id] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        int id = 0;
        // Reconstruct the id in database
        for(int i=0; i<shortUrl.size(); i++) {
            id = 62*id + (int) dict.find(shortUrl[i]);
        }
        
        if(db.find(id) != db.end()) return db[id];
        else return "";
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
