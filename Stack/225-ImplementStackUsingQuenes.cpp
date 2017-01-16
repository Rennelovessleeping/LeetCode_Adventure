/**************************************************************************
 * File Name : 225-ImplementStackUsingQuenes.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 19:22:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push_back(x);    
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop_back();
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    deque<int> q;
    
};
