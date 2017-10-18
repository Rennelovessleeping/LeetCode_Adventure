/**************************************************************************
 * File Name : NormalizeTitle.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 18:04:19 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class NormalizedTitle{
public:
    string getTitle(string rawTitle, vector<string> cleanTitle) {
        string res = "";
        int maxScore = 0;
        for(auto ct:cleanTitle) {
            int curScore = getScore(rawTitle, ct);
            if(curScore > maxScore) {
                maxScore = curScore;
                res = ct;
            }
        }
        return res;
    }

    int getScore(string rawTitle, string cleanTitle) {
        istringstream ss_raw(rawTitle), ss_clean(cleanTitle);
        vector<string> raw, clean;
        string tmp;

        while(ss_raw >> tmp) raw.push_back(tmp);
        while(ss_clean >> tmp) clean.push_back(tmp);

        int score = 0, tmpScore = 0;
        for(int rIdx=0, cIdx=0; rIdx < raw.size() && cIdx < clean.size(); rIdx++) {
            if(raw[rIdx] != clean[cIdx]) {
                cIdx = 0;
                tmpScore = 0;
            }
            else {
                cIdx++;
                tmpScore++;
            }
            score = max(score, tmpScore);
        }

        return score;
    }
};

int main() {

    NormalizedTitle test;
    string rawTitle = "senior software engineer";
    vector<string> cleanTitle = {
        "software engineer",
        "mechanical engineer"
    };

    cout << test.getTitle(rawTitle, cleanTitle);

    return 0;
}
