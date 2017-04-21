/**************************************************************************
 * File Name : 134-GasStation.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 21:25:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, total = 0, tank =0;
        for(int i=0; i<gas.size(); i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) { // cant reach i+1
                start = i+1;
                total += tank; // accumulated cost to overcome the fail 
                tank = 0;
            }
        }
        return (total+tank) < 0 ? -1:start; // by the end, the oil in tank need to be larger than the accumulated cost
    }
};
