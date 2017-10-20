/**************************************************************************
 * File Name : jobID.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Wed Oct 18 22:01:55 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Interval{
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct cmp{
    bool operator() (const Interval& l, const Interval& r) {
        return l.start <= r.start || l.end < r.end;
    }
};

class JobID{
public:
    void expire(int id) {
        Interval tmp(id, id);
        if(expiredJobs.empty()){
            expiredJobs.insert(tmp);
            return;
        }
        //Insertion and Merge;
        auto it = expiredJobs.lower_bound(tmp);
        if(it != expiredJobs.end() && it->end >= id) return;
        if(it != expiredJobs.end() && it->end+1 == id) {
            tmp.start = it->start;
            expiredJobs.erase(it);
        }
        
        it = expiredJobs.lower_bound(tmp);
        if(it != expiredJobs.end() && it->start == id + 1){
            tmp.end = it->end;
            expiredJobs.erase(it);
        }
        expiredJobs.insert(tmp);
    }

    bool isExpired(int id) {
        Interval tmp(id, id);
        auto it = expiredJobs.lower_bound(tmp);
        cout << (it != expiredJobs.end()) << endl;
        
        if(it != expiredJobs.end() && it->start<=id && it->end >= id) return true;
        else return false;
    }
    
//private:
    set<Interval, cmp> expiredJobs;

};
int main(){
    JobID test;
    test.expire(3);
    test.expire(4);
    test.expire(5);
    // auto it = test.expiredJobs.lower_bound(Interval(4,4));
    // cout << it->start << ", " << it->end << endl;
    // it = test.expiredJobs.upper_bound(Interval(4,4));
    // cout << it->start << ", " << it->end << endl;
    // cout << "----------------------------------------------" << endl;
    
    if(test.isExpired(9)) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << "-----------------------------------------------" << endl;
    test.expire(9);
    if(test.isExpired(9)) cout << "Yes" << endl;
    else cout << "No" << endl;

    for(auto item:test.expiredJobs) cout << item.start << ", " << item.end << endl;

    return 0;
}
