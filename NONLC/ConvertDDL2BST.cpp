/**************************************************************************
 * File Name : ConvertDDL2BST.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-02-2017
 *
 * Last Modified : Mon Feb 20 21:26:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
struct Node{
    Node *prev; // left
    Node *next; // right
};

int count_Node(Node *head){
    int cnt = 0;
    Node *tmp = head;
    while(tmp){
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void DDL_to_BST(Node *head){
    int n = count_Node(head);
    constructBST(head, n);
}

Node* constructBST(Node*& head, int n){
    if(n<=0) return;
    // Construct left subtree
    Node *left = constructBST(head, n/2); //After finishing this in the first call, head points to the median now
    Node *root = head;
    root->pre = left;
    head = head->next;

    root->next = constructBST(head, n-n/2-1);
    return root;
}
