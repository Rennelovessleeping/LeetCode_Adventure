/**************************************************************************
 * File Name : 468-ValidateIPAddress.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 19:38:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string validIPAddress(string IP) {
        istringstream ss(IP);
        string block;
        
        // ipv4 candidate;
        if(IP.substr(0, 4).find('.') != string::npos) {
            for(int i=0; i<4; i++) {
                if(!getline(ss, block, '.') || !isValidIPv4(block)) return "Neither";
            }
            return ss.eof() ? "IPv4" : "Neither";
        }
        // ipv6 candidate;
        else if(IP.substr(0, 5).find(':') != string::npos) {
            for(int i=0; i<8; i++) {
                if(!getline(ss, block, ':') || !isValidIPv6(block)) return "Neither";
            }
            return ss.eof() ? "IPv6" : "Neither";
        }
        
        
        return "Neither";
    }
    
private:    
    bool isValidIPv4(const string& block) {
        if(block.size() == 0 || block.size() > 3) return false;
        int num = 0;
        for(int i=0; i<block.size(); i++) {
            char c = block[i];
            if(!isdigit(c) || (i==0 && c=='0' && block.size()>1)) return false;
            else num = num*10 + c - '0';
        }
        return num <= 255;
    }
    
    const string IPv6Chart = "0123456789abcdefABCDEF";
    
    bool isValidIPv6(const string& block) {
        if(block.size() == 0 || block.size() > 4) return false;
        for(int i=0; i<block.size(); i++) {
            char c = block[i];
            if(IPv6Chart.find(c) == string::npos) return false;
        }
        return true;
    }
};
