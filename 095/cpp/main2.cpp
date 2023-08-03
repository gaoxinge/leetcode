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
    vector<TreeNode *> generateTrees(int i, int j) {
        if (i > j) {
            return {nullptr};
        }

        if (j - i == 0) {
            return {new TreeNode(i)};
        }

        std::vector<TreeNode *> result;
        for (int k = i; k < j + 1; k++) {
            auto lefts = generateTrees(i, k - 1);
            auto rights = generateTrees(k + 1, j);
            for (auto &left: lefts) {
                for (auto &right: rights) {
                    result.push_back({new TreeNode(k, left, right)});
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
