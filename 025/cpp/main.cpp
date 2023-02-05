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
    bool full(ListNode *head, int k) {
        int count = 0;
        for (ListNode *temp = head; temp != nullptr && count < k; temp = temp->next, count++);
        return count == k;
    }

    ListNode *reverse(ListNode *head, int k) {
        ListNode *dummy = nullptr;
        for (ListNode *temp = head; k > 0; temp = temp->next, k--) {
            std::cout << temp->val << " ";
            ListNode *t = new ListNode(temp->val, dummy);
            dummy = t;
        }
        return dummy;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *root = new ListNode();
        ListNode *temp = root;
        while (head != nullptr) {
            if (!full(head, k)) {
                temp->next = head;
                break;
            }
            temp->next = reverse(head, k);
            for (int i = 0; i < k; i++, temp = temp->next, head = head->next);
        }
        return root->next;
    }
};
