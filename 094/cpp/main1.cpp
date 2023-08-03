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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *node = s.top();

            if (node != nullptr) {
                s.push(node->left);
            } else {
                s.pop();
                if (!s.empty()) {
                    TreeNode *node = s.top();
                    s.pop();
                    r.push_back(node->val);
                    s.push(node->right);
                }
            }
        }

        return r;
    }
};
