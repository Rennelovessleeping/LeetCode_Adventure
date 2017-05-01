/**************************************************************************
 * File Name : 302-SmallestRectangleEnclosingBlackPixels.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 22:23:42 2017
 *
 * Created By :  Renne Bai
**************************************************************************/



class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = m ? image[0].size() : 0;
        
        int top = searchRow(image, 0, x, 0, n, true);
        int bottom = searchRow(image, x+1, m, 0, n, false);
        int left = searchCol(image, 0, y, top, bottom, true);
        int right = searchCol(image, y+1, n, top, bottom, false);
        
        return (right - left) * (bottom - top);
    }

    int searchCol(vector<vector<char>>& image, int i, int j, int low, int high, bool flag) {
        // flag = true: search left boundary (inclusive)
        // flag = false: search right boundary (exclusive)
        while(i<j) {
            int mid = i + (j-i)/2;
            int k = low;
            while(k < high && image[k][mid] == '0') k++;
            
            if(k < high == flag) j = mid;
            else i = mid + 1;
        }
        
        return i;
    }
    
    int searchRow(vector<vector<char>>& image, int i, int j, int low, int high, bool flag) {
        // flag = true : search for up boundary;
        // flag = false: search for bottom boundary;
        while(i<j) {
            int mid = i + (j-i)/2;
            int k = low;
            while(k<high && image[mid][k] == '0') k++;
            
            if(k<high == flag) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};
