/**************************************************************************
 * File Name : 475-Heaters.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-01-2017
 *
 * Last Modified : Sun Jan 22 19:56:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//naive binary search
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        vector<int> closestDist(houses.size(), 0);
        
        // Search for the closest distance to right neighbors
        for(int i=0;i<houses.size();i++){
            int left = 0, right = heaters.size()-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(heaters[mid] >= houses[i]) right = mid-1;
                else left = mid + 1;
            }
            closestDist[i] = left < heaters.size() ? heaters[left] - houses[i] : INT_MAX;
        }
        
        // Search for the closest distance to left neighbors
        for(int i=0;i<houses.size();i++){
            int left = 0, right = heaters.size()-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(heaters[mid] <= houses[i]) left = mid + 1;
                else right = mid - 1;
            }
            int tmp = right >= 0 ? houses[i] - heaters[right] : heaters[0] - houses[i];
            closestDist[i] = min(closestDist[i], tmp);
        }
        
        return *max_element(closestDist.begin(), closestDist.end());
    }
};

// Combine two kinds of search
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        int closestDist = 0, leftDist, rightDist;
        
        for(int i=0;i<houses.size();i++){
            int left = 0, right = heaters.size()-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(heaters[mid] >= houses[i]) right = mid-1;
                else left = mid + 1;
            }
            leftDist = left < heaters.size() ? heaters[left] - houses[i] : INT_MAX;
            rightDist = right >= 0 ? houses[i] - heaters[right] : INT_MAX;
            closestDist = max(closestDist, min(leftDist, rightDist));
        }
        
        return closestDist;
    }
};
