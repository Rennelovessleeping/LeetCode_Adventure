/**************************************************************************
 * File Name : 271-EncodeAndDecodeString.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 15:16:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The key idea is to use length as prefix and separate prefix from str using seperator char '#'
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(auto str:strs){
            encoded += to_string(str.length()) + '#' + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head = 0;
        while(head<s.length()){
            int end = s.find_first_of('#', head);
            int len = stoi(s.substr(head, end-head));
            head = end + 1;
            res.push_back(s.substr(head, len));
            head += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
