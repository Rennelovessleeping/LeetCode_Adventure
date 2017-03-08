/**************************************************************************
 * File Name : 533-LonlyPixelsII.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 16:52:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// use set<int> to store the idx so we wont need extra space to record the string of each row
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size(), n = m ? picture[0].size() : 0;
        if(m==0 || n==0) return 0;
        
        unordered_map<int,set<int>> colCnt, rowCnt;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] == 'B'){
                    rowCnt[i].insert(j);
                    colCnt[j].insert(i);
                }
            }
        }
        
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] == 'B' && rowCnt[i].size() == N && colCnt[j].size() == N) {
                    res++;
                    for(auto idx:colCnt[j]){
                        if(rowCnt[i] != rowCnt[idx]) {
                            res--;
                            break;
                        }
                    }
                }
            }
        }
        return res;
        
    }
};
