/**************************************************************************
 * File Name : DiceSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 16:29:20 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DiceSum {
public:
    double getProb(int dice, int target) {
        int res = 0;
        // helper(dice, target, res);
        vector<vector<int>> memo(dice+1, vector<int>(target+1, 0));
        res = dfs_memo(dice, target, memo);
        return (double)res / pow(6,dice);
    }
private:
    void helper(int dice, int target, int& res) {
        if(dice == 0 && target == 0) {
            res++;
            return;
        }
        else if(dice <= 0 || target <=0) return;

        for(int i=1; i<=6; i++) {
            helper(dice-1, target-i, res);
        }

    }

    int dfs_memo(int dice, int target, vector<vector<int>>& memo) {
        if(dice == 0 && target == 0) return 1;
        else if(dice <= 0 || target <=0) return 0;
        else if(memo[dice][target] > 0) return memo[dice][target];

        int res = 0;
        for(int i=1; i<=6; i++) {
            res += dfs_memo(dice-1, target-i, memo);
        }

        return memo[dice][target] = res;
    }
};

int main() {

    DiceSum test;
    cout << test.getProb(3, 6) << endl;

    return 0;
}
