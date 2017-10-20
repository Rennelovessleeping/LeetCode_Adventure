/**************************************************************************
 * File Name : RootToLeafMinCost.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 21:40:53 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int val): val(val) {}
};

class RootToLeafMinCost {
public:
    vector<TreeNode*> getMinPath(TreeNode* root){
        if(!root) return {};
        vector<TreeNode*> res, path{root};
        if(!root) return res;
        int minCost = INT_MAX;
        dfs(res, path, root, root->val, minCost);
        return res;
    }

    void dfs(vector<TreeNode*>& res, vector<TreeNode*>& path, TreeNode* root, int curCost, int& minCost) {
        if(!root) return;
        else if(root->children.empty()) {
            if(curCost < minCost) {
                minCost = curCost;
                res.clear();
                for(auto x:path) res.push_back(x);
                return;
            }
        }

        for(auto child:root->children) {
            path.push_back(child);
            dfs(res, path, child, curCost+root->val, minCost);
            path.pop_back();
        }
    }
    
};


int main() {

    RootToLeafMinCost test;
    TreeNode *root = new TreeNode(3);
    root->children = vector<TreeNode*> {
        new TreeNode(4),
        new TreeNode(5),
        new TreeNode(6)
    };

    root->children[0]->children = {
        new TreeNode(2),
        new TreeNode(4)
    };

    root->children[2]->children = {new TreeNode(9)};
    
    vector<TreeNode*> tmp = test.getMinPath(root);
    for(auto x:tmp) cout << x->val << "->";
    cout << endl;

    return 0;
}
