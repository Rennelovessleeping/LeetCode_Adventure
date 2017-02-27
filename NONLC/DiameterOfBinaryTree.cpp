/**************************************************************************
 * File Name : DiameterOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 21:43:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode* construct_tree(vector<string>& preorder, int& pos){
    if(pos == preorder.size()) return nullptr;
    string tmp = preorder[pos++];
    TreeNode *root = tmp == "#" ? nullptr : new TreeNode(stoi(tmp));
    if(root) root->left = construct_tree(preorder, pos);
    if(root) root->right = construct_tree(preorder, pos);
    return root;
}

void preorder_traversal(TreeNode* root){
    if(!root){
        cout << "#, ";
        return;
    }
    cout << root->val << ", ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int calc_diameter(TreeNode* root, int& height){
    int lheight = 0, rheight = 0;
    int ldiameter = 0, rdiameter = 0;

    if(!root) {
        height = 0;
        return 0;
    }

    ldiameter = calc_diameter(root->left, lheight);
    rdiameter = calc_diameter(root->right, rheight);
    height = max(lheight, rheight) + 1;
    
    return max(1+lheight+rheight, max(ldiameter, rdiameter));
}

int main(){
    vector<string> preorder = {"1", "2", "3", "4", "#", "#", "5", "6", "7", "#", "#", "8", "#", "#", "#", "9", "#", "10", "11",
                                "#", "#", "12", "#", "13", "#", "#", "14", "#", "15", "#", "#"};
    int pos = 0;
    TreeNode* root = construct_tree(preorder, pos);
    preorder_traversal(root);
    int pre = 0;
    cout << endl ;
    cout << calc_diameter(root, pre) << endl;
    return 0;
}
