/**************************************************************************
 * File Name : 449-SerializeAndDerializeBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 13:24:59 2017
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream outstr;
        serialize(outstr, root);
        return outstr.str();
    }
    
    void serialize(ostringstream& outstr, TreeNode* root){//Simply do the preorder traversal
        if(!root) return;
        outstr << root->val << ",";
        serialize(outstr, root->left);
        serialize(outstr, root->right);
    }

    // Decodes your encoded data to tree. (Essentially BST node insertion)
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
        
    }
    
    TreeNode* deserialize(string& data, int& pos, int lower, int upper){
        
        // Passing by const ref to data save memory to pass the last test case !!!
        if(pos == data.size()) return nullptr;
        int num = 0, tmpPos = pos;
        while(data[tmpPos]!=',')  num = num*10 + data[tmpPos++]-'0'; 

        tmpPos++; // pass ","

        if(num > upper || num < lower) return nullptr; // the node being explored does not change;
        
        // Create sub-BST using current number;
        pos = tmpPos;
        TreeNode* root = new TreeNode(num);
        root->left = deserialize(data, pos, lower, num);
        root->right = deserialize(data, pos, num, upper);
        
        return root;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
