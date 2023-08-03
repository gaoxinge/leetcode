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
    TreeNode *buildTree(vector<int> &preorder, int pre_i, int pre_j, vector<int> &inorder, int in_i, int in_j) {
        if (pre_j - pre_i == 0) {
            return nullptr;
        }

        int v = preorder[pre_i];
        auto it = std::find(inorder.begin() + in_i, inorder.begin() + in_j, v);
        int idx = std::distance(inorder.begin(), it);

        TreeNode *left = buildTree(preorder, pre_i + 1, pre_i + 1 + idx - in_i, inorder, in_i, idx);
        TreeNode *right = buildTree(preorder, pre_i + 1 + idx - in_i, pre_j, inorder, idx + 1, in_j);
        return new TreeNode(v, left, right);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
