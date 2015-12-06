class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (isBalancedBranch(root) == -1)  return false;
        return true;
    }
    int isBalancedBranch(TreeNode* node) {
        if(!node)  return 0;
        int left = isBalancedBranch(node->left);
        int right = isBalancedBranch(node->right);
        if(left == -1 || right == -1)  return -1;
        if(left - right > 1 || right - left > 1)  return -1;
        return (left > right ? left : right) + 1;
    }
};