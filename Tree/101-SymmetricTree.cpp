/***************************************
* Solution using simple left and right *
* traversal and then comparing them    *
*									   *
***************************************/
class Solution {
public:
    
    std::vector<int> leftList, rightList;
    
    bool isSymmetric(TreeNode* root) {
        
        int i;
        leftTraversal(root);
        rightTraversal(root);
        
        for(i=0;i<leftList.size();i++){
            if(leftList[i]!=rightList[i]){
                return false;
            }
        }
        
        return true;
        
    }
    
    void leftTraversal(TreeNode* root){
        if(root!=NULL){
            leftTraversal(root->left);
            leftList.push_back(root->val);
            leftTraversal(root->right);
        }
        leftList.push_back(NULL);
    }

    void rightTraversal(TreeNode* root){
        if(root!=NULL){
            rightTraversal(root->right);
            rightList.push_back(root->val);
            rightTraversal(root->left);
        }
        rightList.push_back(NULL);
    }
    
};
