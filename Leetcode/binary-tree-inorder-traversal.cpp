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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        
        for(int it: inorderTraversal(root->left)){
            res.push_back(it);
        }
        
        res.push_back(root->val);
        
        for(int it: inorderTraversal(root->right)){
            res.push_back(it);
        }
        return res;
    }
};
