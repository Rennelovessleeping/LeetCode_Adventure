/**************************************************************************
 * File Name : MergeKSortedStream.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 23:51:51 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

class Stream{
    Iterator<Integer> iterator;
    public Stream(List<Integer> list){
        this.iterator = list.iterator();
    }
    public boolean move(){
        return iterator.hasNext();
    }
    public int getValue(){
        return iterator.next();
    }
}

struct Num{
    int val;
    Stream stream;
    Num(Stream stream) {
        this->val = stream.getVaule();
        this->stream = stream;
    }
}

struct cmp{
    bool operator(Num& l, Num& r) {
        return l.val > r.val;
    }
};

class MergeKSortedStream {
    vector<int> getNumberAtLeastKtimes(vector<Stream> lists, int k) {
        vector<int> res;
        if(lists.empty()) return res;

        prority_queue<Num, vector<Num>, cmp> minHeap;
        for(auto& list:lists) {
            Num tmp(list);
            if(list.move()) minHeap.push(tmp);
        }

        while(!minHeap.empty()) {
           int count = 1;
           Num cur = minHeap.top(); minHeap.pop();
           int curval = cur.val;
           while(cur.stream.move()){
               int nextval = cur.stream.getValue();
               if(nextval == curval) continue;
               else {
                   cur.val = nextval;
                   minHeap.push(cur);
                   break;
               }
           }

            while(!minHeap.empty() && curvalue == minHeap.top().val) {
               count++;
               Num tmp = minHeap.top(); minHeap.pop();

               while(tmp.stream.move()) {
                   int nextval = tmp.stream.getValue();
                   if(curalue == nextval) continue;
                   else {
                       tmp.val = nextval;
                       minHeap.push(tmp);
                       break;
                   }
               }
            }

            if(count >= k) res.push_back(curval);
        }

        return res;
    }
}


int main() {

    return 0;
}
