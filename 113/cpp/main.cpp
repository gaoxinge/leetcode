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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }

        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            return {{root->val}};
        }

        auto lefts = pathSum(root->left, targetSum);
        auto rights = pathSum(root->right, targetSum);
        
        vector<vector<int>> result;
        for (auto &left: lefts) {
            left.insert(left.begin(), root->val);
            result.push_back(left);
        }
        for (auto &right: rights) {
            right.insert(right.begin(), root->val);
            result.push_back(right);
        }
        return result;
    }
};
