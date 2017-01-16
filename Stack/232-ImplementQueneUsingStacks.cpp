/**************************************************************************
 * File Name : 232-ImplementQueneUsingStacks.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 19:15:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Using another stack to realized pop() & top();
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> t;
        while(!s.empty()) {t.push(s.top()); s.pop();}
        t.pop();
        while(!t.empty()) {s.push(t.top()); t.pop();}
    }

    // Get the front element.
    int peek(void) {
        stack<int> t;
        while(!s.empty()) {t.push(s.top()); s.pop();}
        int front = t.top();
        while(!t.empty()) {s.push(t.top()); t.pop();}
        return front;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s;
    
};

// Using only one stack
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        reversePush(x);
    }
    
    void reversePush(int x){
        if(s.size()==0) {s.push(x); return;}
        int tmp = s.top();
        s.pop();
        reversePush(x);
        s.push(tmp);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s;
    
};
