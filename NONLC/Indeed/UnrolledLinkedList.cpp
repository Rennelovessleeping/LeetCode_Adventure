/**************************************************************************
 * File Name : UnrolledLinkedList.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 17:30:21 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string chars;
    int len; // actual filled length of chars;
    Node* next;
    Node(string chars): next(nullptr) {
        this->chars = chars;
        len = chars.size();
    }
};

class LinkedList{
public:
    Node *head;
    int tot_len;
    
    LinkedList(Node *head, int tot_len) {
        this->head = head;
        this->tot_len = tot_len;

        tot_len = 0;
        Node *p = head;
        while(p) {
            tot_len += p->len;
            p = p->next;
        }
    }

    char get(int idx) {
        if(idx < 0 || idx >= tot_len) return ' ';

        Node* p = head;
        while(p && idx>=0) {
            if(idx >= p->len) idx -= p->len;
            else return p->chars[idx];

            p = p->next;
        }
        return ' ';
    }

    void insert(char ch, int idx) {
        // last insertion point is that passing the end by one
        cout << idx << ", " << tot_len << endl;
        if(idx > tot_len) return;

        Node *p = head;
        while(p && idx >= 0) {
            if(idx >= p->len) { // find the insertion node first of all
                idx -= p->len;
                p = p->next;
            }
            else {
                cout << "Insertion Node: " << p->chars << endl;
                if(p->len == 5) {
                    Node *tmp = new Node(string(5, ' '));
                    tmp->chars[0] = p->chars[4];
                    tmp->len = 1;
                    tmp->next = p->next;
                    p->next = tmp;
                    p->len -=1;
                }

                p->len += 1;
                int i=p->len-1;
                for(; i>idx; i--) {
                   p->chars[i] = p->chars[i-1]; 
                }
                p->chars[i] = ch;
                break;
            }
        }
    }

    void print() {
        Node *p = head;
        while(p) {
            cout << p->len << ", "  <<  p->chars << endl << "---------------------------"  <<  endl;
            p = p->next;
        }
    }

};

int main() {

    Node *n1 = new Node("ab");
    Node *n2 = new Node("b");
    Node *n3 = new Node("abcde");

    n1->next = n2;
    n2->next = n3;

    LinkedList *head = new LinkedList(n1, 8);

    head->insert('A', 3);
    head->print();
    
    return 0;
}
