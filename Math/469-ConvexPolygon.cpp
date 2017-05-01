/**************************************************************************
 * File Name : 469-ConvexPolygon.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 21:13:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// p_{i+1}-p_i cross p_{i+2} - p_i should keep the same sign through all the vortex
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        for(int i=0, pos=0, neg=0; i<n; i++) {
            long det = det2D(points[i], points[(i+1)%n], points[(i+2)%n]);
            if((pos |= det>0) && (neg |= det<0)) return false;
        }
        
        return true;
    }
    
    long det2D(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        return (p3[0]-p1[0])*(p2[1]-p1[1]) - (p3[1]-p1[1])*(p2[0]-p1[0]);
    }
};
