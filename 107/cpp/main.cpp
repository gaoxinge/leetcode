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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> q = {root};
        while (!q.empty()) {
            vector<int> r;
            vector<TreeNode *> newQ;
            for (auto &node: q) {
                if (node != nullptr) {
                    r.push_back(node->val);
                    newQ.push_back(node->left);
                    newQ.push_back(node->right);
                }
            }
            if (!r.empty()) {
                result.push_back(r);
            }
            q = newQ;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
