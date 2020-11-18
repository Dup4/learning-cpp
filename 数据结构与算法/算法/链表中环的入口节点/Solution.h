/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pos = nullptr;
        while (fast || slow) {
            if (fast) fast = fast->next;
            if (fast) fast = fast->next;
            if (slow) slow = slow->next;
            if (fast && slow && fast == slow) {
                pos = fast;
                break;
            }
        }
        if (pos == nullptr) return nullptr;
        ListNode* tmp = head;
        while (head != pos) {
            head = head->next;
            pos = pos->next;
        }
        return pos;
    }
};