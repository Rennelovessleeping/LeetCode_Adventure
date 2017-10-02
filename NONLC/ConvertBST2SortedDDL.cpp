/**************************************************************************
 * File Name : ConvertBST2SortedDDL.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-02-2017
 *
 * Last Modified : Thu Sep 28 12:42:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Convert BST to sorted cicular double linked list (DDL) 
// Recusersive solution

struct Node{
    Node *left;
    Node *right;
};

void BST_to_DDL(Node *p, Node& *prev, Node&* head){
    
    if(!p) return;
    // Convert the left subtree to sorted DDL in place:
    BST_to_DDL(p->left, prev, head);

    if(prev) prev->right = p;
    else head = p; // The only chance to change head is reaching leftmost leaf or the left subtree of root is empty

    Node *r = p->right;
    p->right = head;
    head->left = p;
    prev = p;

    // Convert the right subtree to left DDL + root;
    BST_to_DDL(r, prev, head);
}

// Function overloading can not only differs by only return type
Node* BST_to_DDL(Node* root){
    Node *head = nullptr, *prev = nullptr;
    BST_to_DDL(root, head, prev);
    return head;
}
