/**************************************************************************
 * File Name : 385-MiniParser.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-04-2017
 *
 * Last Modified : Wed Apr  5 18:45:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// use a stack to store the current NestedInteger;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {

        stack<NestedInteger> stk;
        stk.push(NestedInteger()); // Since we can not judge whether a nestedInteger obj is empty or not;
        int j=0; // left ptr to substring denoting a number;
        
        for(int i=0; i<s.length(); ){
            if(s[i] == '-' || isdigit(s[i])) {
                int num = 0;
                int sign = s[i]=='-' ? -1 : 1;
                if(sign == -1) i++;
                while(isdigit(s[i])) {
                    num = num*10 + s[i] - '0';
                    i++;
                }
                stk.top().add(NestedInteger(num*sign));
            }
            else {
                if(s[i] == '[') stk.push(NestedInteger()); // start a new nested list;
                else if(s[i] == ']') { // end current deepest list;
                    NestedInteger tmp = stk.top();
                    stk.pop();
                    stk.top().add(tmp);                
                }
                i++;
            }
            
        }
        
        return stk.top().getList().front(); // Remeber that we put an empty nestedList object in the stack;
    }
};

// Use istringstream obj
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream ss(s);
        return deserialize(ss);
    }
    
    NestedInteger deserialize(istringstream& ss) {
        int num;
        if(ss >> num) return num;
        ss.clear();  // clear the flag for not able to read an integer;
        ss.get(); // pass the '['
        
        NestedInteger res;
        while(ss.peek() != ']'){
            res.add(deserialize(ss));
            if(ss.peek() == ',') ss.get();
        }
        ss.get();
        return res;
    }
};
