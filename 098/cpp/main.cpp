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
    std::vector<int> getPreorder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        auto leftPreorder = getPreorder(root->left);
        auto rightPreorder = getPreorder(root->right);
        leftPreorder.push_back(root->val);
        std::copy(rightPreorder.begin(), rightPreorder.end(), std::back_inserter(leftPreorder));
        return leftPreorder;
    }

    bool isValidBST(TreeNode* root) {
        std::vector<int> preorder = getPreorder(root);
        std::cout << std::endl;
        for (int i = 1; i < preorder.size(); i++) {
            if (preorder[i] <= preorder[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
