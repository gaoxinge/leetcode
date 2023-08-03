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
    void getInorder(TreeNode *root, std::vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        getInorder(root->left, result);
        result.push_back(root->val);
        getInorder(root->right, result);
    }

    bool isValidBST(TreeNode* root) {
        std::vector<int> inorder;
        getInorder(root, inorder);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

