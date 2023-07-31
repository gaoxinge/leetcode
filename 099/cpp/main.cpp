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
    void swap(TreeNode *a, TreeNode *b) {
        int t = a->val;
        a->val = b->val;
        b->val = t;
    }

    void infixTree(TreeNode *root, std::vector<TreeNode *> &result) {
        if (root == nullptr) {
            return;
        }
        infixTree(root->left, result);
        result.push_back(root);
        infixTree(root->right, result);
    }

    void recoverTree(TreeNode* root) {
        std::vector<TreeNode *> result;
        infixTree(root, result);

        TreeNode *left;
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i]->val > result[i + 1]->val) {
                left = result[i];
                break;
            }
        }

        TreeNode *right;
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i - 1]->val > result[i]->val) {
                right = result[i];
                break;
            }
        }

        swap(left, right);
    }
};
