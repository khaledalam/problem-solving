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
    
    vector<int> parse(TreeNode* node){
        
        if(node == NULL) return {};
        
        vector<int>ret;
        ret.push_back(node->val);
        
        for(auto &it: parse(node->left))ret.push_back(it);
        for(auto &it: parse(node->right))ret.push_back(it);
        
        return ret;
    }
    
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        map<long long,bool>vis;
        
        vector<int> f = parse(root1);
        vector<int> l = parse(root2);
        
        for(auto &it: f){
            // cout<<it<<" ";
            vis[it] = true;
        }
        for(auto &it: l){
            if(vis[abs(it - target)])return true;
            if(vis[abs(it + target)])return true;
            if(vis[target - it])return true;
            if(vis[it - target])return true;
        }
        
        
        return false;
        
    }
};
