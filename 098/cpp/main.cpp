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
    std::vector<int> getInorder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        auto leftPreorder = getInorder(root->left);
        auto rightPreorder = getInorder(root->right);
        leftPreorder.push_back(root->val);

        // leftPreorder.reserve(leftPreorder.size() + std::distance(rightPreorder.begin(), rightPreorder.end()));
        // leftPreorder.insert(leftPreorder.end(), rightPreorder.begin(), rightPreorder.end());
        std::copy(rightPreorder.begin(), rightPreorder.end(), std::back_inserter(leftPreorder));

        return leftPreorder;
    }

    bool isValidBST(TreeNode* root) {
        std::vector<int> inorder = getInorder(root);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

