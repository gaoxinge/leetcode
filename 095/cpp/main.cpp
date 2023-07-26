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
    std::vector<std::vector<int>> generate(int n) {
        if (n == 1) {
            return {{1}};
        }

        auto result = generate(n - 1);
        std::vector<std::vector<int>> result0;
        for (auto &r: result) {
            for (int i = 0; i < n; i++) {
                std::vector<int> r0(r);
                r0.insert(r0.begin() + i, n);
                result0.push_back(r0);
            }
        }

        return result0;
    }

    TreeNode *generateTree(std::vector<int> inorder, std::vector<int> preorder, bool &check) {
        if (inorder.empty()) {
            check = true;
            return nullptr;
        }

        int t = inorder[0];
        auto it = std::find(preorder.begin(), preorder.end(), t);
        if (it == preorder.end()) {
            check = false;
            return nullptr;
        }

        int leftNum = std::distance(preorder.begin(), it);
        int rightNum = preorder.size() - 1 - leftNum;
        std::vector<int> leftInorder(inorder.begin() + 1, inorder.begin() + 1 + leftNum);
        std::vector<int> leftPreorder(preorder.begin(), it);
        std::vector<int> rightInorder(inorder.end() - rightNum, inorder.end());
        std::vector<int> rightPreorder(it + 1, preorder.end());

        bool leftCheck, rightCheck;
        auto left = generateTree(leftInorder, leftPreorder, leftCheck);
        auto right = generateTree(rightInorder, rightPreorder, rightCheck);
        if (!leftCheck || !rightCheck) {
            check = false;
            return nullptr;
        }
        check = true;
        return new TreeNode(t, left, right);
    }

    vector<TreeNode*> generateTrees(int n) {
        std::vector<int> preorder;
        for (int i = 0; i < n; i++) {
            preorder.push_back(i + 1);
        }

        auto inorders = generate(n);
        std::vector<TreeNode *> result;
        for (auto &inorder: inorders) {
            bool check;
            auto r = generateTree(inorder, preorder, check);
            if (r != nullptr) {
                result.push_back(r);
            }
        }
        
        return result;
    }
};
