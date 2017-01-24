/**************************************************************************
 * File Name : 104-MaximumDepthOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 14:00:29 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//DFS
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

// BFS using queue
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        
        if(!root) return depth;
        q.push(root);
        
        while(!q.empty()){
            depth++;
            for(int i=0, len=q.size(); i<len ;i++) // Note that the size of q changes per round
                TreeNode* p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        
        return depth;
    }
};


