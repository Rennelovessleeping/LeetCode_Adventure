/**************************************************************************
 * File Name : InorderSuccesorBST_parent.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-10-2017
 *
 * Last Modified : Mon Oct 16 14:58:51 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// We are not given values of each node, but their parent node instead
TreeNode* inorderSuccesor(TreeNode* root, TreeNode* p) {
    if(!p->right) return minVal(p);
    TreeNode *parent = p->parent;
    while(parent && p == parent->right) {
        p = parent;
        parent = parent->parent;
    }

    return parent;
}

TreeNode *minVal(TreeNode* root) {
    while(root->left) root = root->left;
    return root;
}
