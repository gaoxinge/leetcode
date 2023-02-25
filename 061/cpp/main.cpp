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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        
        int n = 0;
        ListNode *first = head;
        for (; n < k && first->next != nullptr; n++, first = first->next) ;

        ListNode *second = head;
        if (first->next == nullptr) {
            std::cout << n << std::endl;
            n++;
            k = n - 1 - k % n;
            for (int i = 0; i < k; i++, second = second->next) ;
        } else {
            for (; first->next != nullptr; first = first->next, second = second->next) ;
        }

        if (first == second) {
            return head;
        }
        ListNode *root = second->next;
        second->next = nullptr;
        first->next = head;
        return root;
    }
};
