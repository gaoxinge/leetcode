/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node *> next = {root};
        while (!next.empty()) {
            vector<Node *> next_;
            for (int i = 0; i < next.size(); i++) {
                if (i < next.size() - 1) {
                    next[i]->next = next[i + 1];
                }
                if (next[i]->left != nullptr) {
                    next_.push_back(next[i]->left);
                }
                if (next[i]->right != nullptr) {
                    next_.push_back(next[i]->right);
                }
            }
            next = next_;
        }
        return root;
    }
};
