/**************************************************************************
 * File Name : SuperWashingMachine.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-04-2017
 *
 * Last Modified : Tue Apr 25 20:08:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        vector<int> presum(n+1, 0);
        for(int i=1; i<=n; i++) presum[i] = presum[i-1] + machines[i-1];
        if(presum[n] % n != 0) return -1;
        
        int target = presum[n]/n, res = 0; // res - maximum operation on individual washing machine
        for(int i=0; i<n; i++) {
            int l = i*target - presum[i];
            int r = (n-1-i)*target - (presum[n] - presum[i+1]);
            if(l > 0 && r > 0) res = max(res, l+r);
            else res = max(res, max(abs(l), abs(r)));
        }
        
        return res;
    }
};
