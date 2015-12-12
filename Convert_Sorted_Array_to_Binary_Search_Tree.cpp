class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())  return NULL;
        return sortedArrayToBranch(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBranch(vector<int>& nums, int low, int high) {
        if(high < low)  return NULL;
        if(low == high){
            TreeNode* node = new TreeNode(nums[low]);
            return node;
        }
        int height = (high - low) / 2;
        TreeNode* node = new TreeNode(nums[low+height]);
        node->left = sortedArrayToBranch(nums, low, low + height - 1);
        node->right = sortedArrayToBranch(nums, low + height + 1, high);
        return node;
    }
};