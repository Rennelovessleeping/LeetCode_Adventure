/**************************************************************************
 * File Name : 285-InorderSuccessorInBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-02-2017
 *
 * Last Modified : Fri Feb 10 22:21:36 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Naive solution of generating inorder traversal sequence then make a linear search
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        genInorder(inorder, root);
        int i;
        for(i=0;i<inorder.size() && inorder[i]!=p ;i++){}
        return i+1 < inorder.size() ? inorder[i+1] : nullptr; 
    }
    
private:
    vector<TreeNode* > inorder;
    void genInorder(vector<TreeNode*>& inorder, TreeNode* root){
        if(!root) return;
        genInorder(inorder, root->left);
        inorder.push_back(root);
        genInorder(inorder, root->right);
    }
};


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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        genInorder(inorder, root);
        int i;
        for(i=0;i<inorder.size() && inorder[i]!=p ;i++){}
        return i+1 < inorder.size() ? inorder[i+1] : nullptr; 
    }
    
private:
    vector<TreeNode* > inorder;
    void genInorder(vector<TreeNode*>& inorder, TreeNode* root){
        if(!root) return;
        genInorder(inorder, root->left);
        inorder.push_back(root);
        genInorder(inorder, root->right);
    }
};

// Recursive Solution
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return nullptr;
        if(root->val <= p->val) return inorderSuccessor(root->right, p);
        TreeNode *ptr = inorderSuccessor(root->left, p);
        return ptr ? ptr : root; 
        // if ptr is null, then ptr points to the largest elem in left subtree and root is the successor;
    }
    
};
