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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<tuple<TreeNode *, int>> s;
        s.push({root, 0});

        while (!s.empty()) {
            tuple<TreeNode *, int> t = s.top();
            TreeNode *node = get<0>(t);
            int cnt = get<1>(t);
            
            if (node == nullptr) {
                s.pop();
                if (!s.empty()) {
                    t = s.top();
                    s.pop();
                    s.push({get<0>(t), get<1>(t) + 1});
                }
                continue;
            }

            if (cnt == 0) {
                s.push({node->left, 0});
            } else if (cnt == 1) {
                s.push({node->right, 0});
            } else {
                s.pop();
                r.push_back(node->val);
                if (!s.empty()) {
                    t = s.top();
                    s.pop();
                    s.push({get<0>(t), get<1>(t) + 1});
                }
            }
        }

        return r;
    }
};
