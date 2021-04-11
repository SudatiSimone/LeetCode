/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair <int,int> res; //depth & count
    
    void dfs (TreeNode* root, int depth){
        if (root == NULL) return; 
        if (res.first<depth){
            res.first=depth;
            res.second=root->val;
        } else if (res.first==depth){
            res.second+=root->val;
        } else if(res.first>depth){
            // do nothing
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        res.first=-1; res.second=-1;
        dfs(root, 0);
        return res.second;
        
    }
};