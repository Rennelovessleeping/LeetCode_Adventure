/**************************************************************************
 * File Name : 48-RotateImage.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-02-2017
 *
 * Last Modified : Fri Feb 17 21:34:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Turn the image up-down first, then swap the elements that are symmetric w.r.t. diagonal line
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); ++i){
            for(int j=i+1; j<matrix[i].size(); ++j) swap(matrix[i][j], matrix[j][i]);
        }
    }
};
