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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root)  return NULL;
        TreeNode* newLeft = root->right;
        TreeNode* newBranch = root->left;
        if(newBranch != NULL) {
          TreeNode* newRoot = upsideDownBinaryTree(root->left);
          newBranch->right = root;
          root->left = NULL;
          root->right = NULL;
          newBranch->left = newLeft;
          return newRoot;
        }
        else  return root;
        
    }
};