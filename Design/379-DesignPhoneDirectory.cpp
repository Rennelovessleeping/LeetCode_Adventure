/**************************************************************************
 * File Name : 379-DesignPhoneDirectory.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 12:33:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class PhoneDirectory {
private:
    vector<bool> available;
    vector<int> numbers;
    int idx, cnt;
    
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers): idx(0), cnt(maxNumbers), available(maxNumbers, true), numbers(maxNumbers) {
        for(int i=0; i<cnt; i++) numbers[i] = i;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int res = -1;
        if(idx < cnt) {
            res = numbers[idx++];
            available[res] = false;
        }
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number < 0 || number >= cnt) return false;
        return available[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number < 0 || number >= cnt || available[number]) return;
        numbers[--idx] = number;
        available[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
