/**************************************************************************
 * File Name : 281-ZigzagIterator.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 22:39:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) q.push({v1.begin(), v1.end()});
        if(!v2.empty()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto tmp = q.front(); q.pop();
        int res = *tmp.first;
        if(++tmp.first != tmp.second) q.push(tmp);
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
