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
    TreeNode *buildTree(vector<int> &inorder, int in_i, int in_j, vector<int> &postorder, int post_i, int post_j) {
        if (in_j - in_i == 0) {
            return nullptr;
        }

        int v = postorder[post_j - 1];
        auto it = std::find(inorder.begin() + in_i, inorder.begin() + in_j, v);
        int idx = std::distance(inorder.begin(), it);

        auto left = buildTree(inorder, in_i, idx, postorder, post_i, post_i + idx - in_i);
        auto right = buildTree(inorder, idx + 1, in_j, postorder, post_i + idx - in_i, post_j - 1);
        return new TreeNode(v, left, right);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
