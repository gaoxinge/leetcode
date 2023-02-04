/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *left, ListNode *right) { return left->val > right->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);
        for (auto &n: lists) {
            if (n != nullptr) {
                q.push(n);
            }
        }
        ListNode *root = new ListNode();
        ListNode *temp = root;
        while (!q.empty()) {
            ListNode *n = q.top();
            q.pop();
            temp->next = new ListNode(n->val);
            temp = temp->next;
            if (n->next != nullptr) {
                q.push(n->next);
            }
        }
        return root->next;
    }
};
