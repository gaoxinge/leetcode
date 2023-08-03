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
    TreeNode *sortedArrayToBST(vector<int> &nums, int i, int j) {
        if (j - i == 0) {
            return nullptr;
        }
        int k = i + (j - i) / 2;
        auto left = sortedArrayToBST(nums, i, k);
        auto right = sortedArrayToBST(nums, k + 1, j);
        return new TreeNode(nums[k], left, right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
