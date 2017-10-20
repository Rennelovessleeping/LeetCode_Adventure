/**************************************************************************
 * File Name : BinaryTree2Array.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 23:20:26 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

class BT_to_Array {
    vector<int> compressDenseTree(TreeNode* root) {
        int height = getHeight(root);
        vector<int> res((int)pow(2, height));
        queue<pair<TreeNode*, int>> q; // {ptr to node, idx in arr}
        q.push({root,0});

        while(!q.empty) {
            auto tmp = q.front().first; 
            int idx = q.front().second;
            q.pop();
            res[idx] = tmp->val;

            if(tmp->left) q.push({tmp, 2*idx+1});
            if(tmp->right) q.push({tmp, 2*idx+2});
        }

        return res;
    }

    int getHeight(TreeNode* root) {
        if(!root) return 0;
        int lh = getHeight(root->left), rh = getHeight(root->right);
        return max(lh, rh)+1;
    }
}

int main() {

    return 0;
}
