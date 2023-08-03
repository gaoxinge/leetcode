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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> q = {root};
        int level = 0;
        while (!q.empty()) {
            vector<int> r;
            vector<TreeNode *> newQ;
            if (level % 2 == 0) {
                for (auto &node: q) {
                    if (node != nullptr) {
                        r.push_back(node->val);
                    }
                }
            } else {
                for (auto it = q.rbegin(); it != q.rend(); it++) {
                    auto node = *it;
                    if (node != nullptr) {
                        r.push_back(node->val);
                    }
                }
            }
            for (auto &node: q) {
                if (node != nullptr) {
                    newQ.push_back(node->left);
                    newQ.push_back(node->right);
                }
            }
            if (!r.empty()) {
                result.push_back(r);
            }
            q = newQ;
            level++;
        }
        return result;
    }
};
