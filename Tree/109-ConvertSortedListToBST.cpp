/**************************************************************************
 * File Name : 109-ConvertSortedListToBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 13:28:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head) return nullptr;
        ListNode *p = head;
        while(p->next) p=p->next;
        return helper(head, p);
        
    }

private:
    TreeNode* helper(ListNode* head, ListNode* end){
        
        if(head == end) return new TreeNode(head->val);
        if(head == end->next) return nullptr;
        
        ListNode* slow=head, *fast=head;
        ListNode* tail = new ListNode(-1);
        tail->next = head;
        
        while(fast != end && fast->next !=end){
            slow = slow->next;
            tail = tail->next;
            fast = fast->next->next;
        }
        if(fast->next == end){
            fast = fast->next;
            slow = slow->next;
            tail = tail->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);    
        root->left = helper(head, tail);
        root->right = helper(slow->next, end);
        
        return root;
        
    }
};

// In-order traversal;
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *ptr = head;
        int nodeNum = 0;
        while(ptr){
            nodeNum++;
            ptr = ptr->next;
        }
        ptr = head;
        return makeBST(nodeNum, ptr);
    }

private:
    TreeNode* makeBST(int n, ListNode* &node){ // By inorder traversal
        if (n==0) return nullptr;
        TreeNode *root = new TreeNode(-1);
        root->left = makeBST(n/2, node);
        root->val = node->val;
        node = node->next; // move on to the next list node till reach the left most node on BST
        root->right = makeBST(n-1-n/2, node);
        
        return root;
    } 

};

