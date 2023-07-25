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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp;

        std::vector<int> xs;
        temp = head;
        for (int i = 1; temp != nullptr; i++, temp = temp->next) {
            if (i <= left || i > right) {
                xs.push_back(temp->val);
            } else {
                xs.insert(xs.begin() + left - 1, temp->val);
            }
        }

        ListNode *root = new ListNode();
        temp = root;
        for (auto &x: xs) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return root->next;
    }
};
