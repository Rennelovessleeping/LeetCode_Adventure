/**************************************************************************
 * File Name : 297-SerializeAndDeserializeBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-02-2017
 *
 * Last Modified : Sat Feb 11 20:26:44 2017
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
        ostringstream ostr;
        serialize_helper(ostr, root);
        return ostr.str();
    }
    
    void serialize_helper(ostringstream& ostr, TreeNode* root){
        if (!root) {
            ostr << "# ";
            return;
        }
        ostr << to_string(root->val) << " ";
        serialize_helper(ostr, root->left); 
        serialize_helper(ostr, root->right);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream istr(data);
        return deserialize_helper(istr);
    }
    
    TreeNode * deserialize_helper(istringstream& istr){
        string val; istr >> val;
        if(val=="#") return nullptr; 
        TreeNode *root = new TreeNode(stoi(val));
        root->left =  deserialize_helper(istr);
        root->right = deserialize_helper(istr);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

