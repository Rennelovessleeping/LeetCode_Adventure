/**************************************************************************
 * File Name : 105-ConstructBinaryTreefromPreorderAndInorderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 15:54:44 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Recursive Solution
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
private:
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
        if(preE < preS) return nullptr;
        TreeNode* node = new TreeNode(preorder[preS]);
        int pos;
        for(pos=inS; pos<=inE; pos++){
            if(inorder[pos]==preorder[preS]) break;
        }
        
        node->left = createTree(preorder, inorder, preS+1, preS+pos-inS, inS, pos-1);
        node->right = createTree(preorder, inorder, preS+pos-inS+1, preE, pos+1, inE);
        return node;
    }
};

