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
    void levelOrder(vector<TreeNode *> roots, vector<vector<int>> &result) {
        if (roots.empty()) {
            return;
        }
        vector<int> r;
        vector<TreeNode *> newRoots;
        for (auto &root: roots) {
            if (root != nullptr) {
                r.push_back(root->val);
                newRoots.push_back(root->left);
                newRoots.push_back(root->right);
            }
        }
        if (!r.empty()) {
            result.push_back(r);
        }
        levelOrder(newRoots, result);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder({root}, result);
        return result;
    }
};
