/**************************************************************************
 * File Name : 106-ConstructBinaryTreefromInorderAndPostorderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 15:38:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//Recursive solution
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
private:
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,int inStart, int inEnd, int postStart, int postEnd){
        
        if(postEnd < postStart) return nullptr;
        int pos; // root of current subtree
        TreeNode * node = new TreeNode(postorder[postEnd]);
        
        for(pos=inStart;pos<=inEnd;pos++){
            if (inorder[pos] == postorder[postEnd]) break;
        }
        
        node->left = createTree(inorder, postorder, inStart, pos-1, postStart, postStart+pos-inStart-1);
        node->right = createTree(inorder, postorder, pos+1, inEnd, postEnd-inEnd+pos, postEnd-1);
        return node;
        
    }
};

// How to solve this in an iterative way?
