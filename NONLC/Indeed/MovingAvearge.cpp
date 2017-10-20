/**************************************************************************
 * File Name : MovingAvearge.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 23:07:08 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <queue>

// Given API getNow()
class MovingAverage {
public:
    bool isExpired(int curtime, int pretime){
        return curtime - pretime > 300;
    }

    void record(int val) {
        q.push({val, getNow()});
        sum += val;
        removeExpired();
    }

    void removeExpired(){
        int curtime = getNow();
        while(!q.empty() && isExpired(q.front()).second) {
            sum -= q.front().first;
            q.pop();
        }
    }

    double getAvg() {
        removedExpired();
        return q.empty() ? 0.0 : sum/(double) q.size();
    }
    
private:
    queue<pair<int,int>> q; // {val, timestamp}
    int sum = 0;
};

using namespace std;


int main() {

    return 0;
}
