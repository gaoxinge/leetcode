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
    ListNode *swap(ListNode *head) {
        ListNode *a = new ListNode(head->val);
        if (head->next == nullptr) {
            return a;
        }
        return new ListNode(head->next->val, a);
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode *root = new ListNode();
        ListNode *temp = root;
        while (head != nullptr) {
            ListNode *t = swap(head);
            temp->next = t;
            temp = temp->next;
            head = head->next;
            if (head == nullptr) {
                break;
            }
            temp = temp->next;
            head = head->next;
        }
        return root->next;
    }
};
