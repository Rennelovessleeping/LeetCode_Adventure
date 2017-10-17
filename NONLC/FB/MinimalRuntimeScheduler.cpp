/**************************************************************************
 * File Name : MinimalRuntimeScheduler.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-02-2017
 *
 * Last Modified : Sat Feb 25 21:34:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minimalRuntimeScheduler(vector<int>& tasks, int cooldown){
    int res = 0, i = 0;
    unordered_map<int, int> mp;
    while(i < tasks.size()){
        if(mp.find(tasks[i]) == mp.end() || mp[tasks[i]] < res-cooldown) {
            mp[tasks[i++]] = res;
        }
        res++;
    }
    return res;
}

int main(){
    vector<int> tasks = {1, 2, 1, 1};	
	int cooldown = 2;
	cout << "Total time is" << minimalRuntimeScheduler(tasks, cooldown) << endl;
    return 0;
}

