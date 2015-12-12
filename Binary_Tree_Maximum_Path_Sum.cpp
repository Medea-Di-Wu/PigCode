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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxBranchSum(root, maxSum);
        return maxSum;
    }
    int maxBranchSum(TreeNode* node, int& maxSum) {
        if(node == NULL)  return 0;
        int left = maxBranchSum(node->left, maxSum);
        int right = maxBranchSum(node->right, maxSum);
        /*int localMax = node->val;
        localMax = max(left + node->val, localMax);
        localMax = max(node->val + right, localMax);*/
        int localMax = node->val + max(left, right);
        
        //maxSum = max(localMax, maxSum);
        maxSum = max(left + node->val + right, maxSum);
        //return localMax;
        return localMax > 0 ? localMax : 0;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
};