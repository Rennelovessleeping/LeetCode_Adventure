/**************************************************************************
 * File Name : 95-UniqueBST-II.cpp
 *
 * Purpose : DP solution
 *
 * Creation Date : 12-01-2017
 *
 * Last Modified : Thu Jan 12 23:04:13 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
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
    vector<TreeNode*> generateTrees(int n) {
        
        if(n==0) return vector<TreeNode*>();
        vector<TreeNode*> prevTrees(1, nullptr);
    
        for(int i=1;i<=n;i++){
            vector<TreeNode*> curTrees;
            for(int j=0;j< prevTrees.size();j++){
                TreeNode* oldRoot = prevTrees[j];
                
                // case 1: i is the new root
                TreeNode* root = new TreeNode(i);
                root->left = clone(oldRoot);
                curTrees.push_back(root);
                
                // case 2: i is not the new root
                if(oldRoot!=nullptr){
                    TreeNode* ptr = oldRoot;
                    while(ptr->right){
                        TreeNode* root = new TreeNode(i);
                        TreeNode* rightCopy = ptr->right;
                        root->left = ptr->right;
                        ptr->right = root;
                        TreeNode* BSTcopy = clone(oldRoot);
                        curTrees.push_back(BSTcopy);
                        
                        // Recovery old BST
                        ptr->right = rightCopy;
                        ptr = ptr->right;
                        
                    } // end of while
                    ptr->right = new TreeNode(i); // Rightmost leaf
                    TreeNode* BSTcopy = clone(oldRoot);
                    curTrees.push_back(BSTcopy);
                    ptr->right = nullptr;
                    
                    /* DO NOT ALTER THE OLD BST IN PrevTrees!!*/
                    
                } // end of if
                
            }
            prevTrees = curTrees;
        }
        
        return prevTrees;

    }

private:
    TreeNode* clone(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        
        return newRoot;
    }
    
};
