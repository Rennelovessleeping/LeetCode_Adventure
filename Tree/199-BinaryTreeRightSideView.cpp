/**************************************************************************
 * File Name : 199-BinaryTreeRightSideView.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 20:50:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS soluton using queue
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> pre;
        pre.push(root);
        
        while(!pre.empty()){
            res.push_back(pre.back()->val);
            queue<TreeNode*> cur;
            while(!pre.empty()) {
                TreeNode* p = pre.front();
                pre.pop();
            
                if(p->left) cur.push(p->left);
                if(p->right) cur.push(p->right);
            }
            pre.swap(cur);
        }
        
        return res;
    }
};

// BFS + DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(res, 1, root);
        return res;
    }
    
private:
    void helper(vector<int>& res, int level, TreeNode *root){
        if(!root) return;
        if(res.size() < level) res.push_back(root->val);
        helper(res, level+1, root->right); // the most right node is first visited, while the left most one is visted last.
        helper(res, level+1, root->left);
    }
    
};
