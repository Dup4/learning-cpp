/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
    bool isSame(ListNode *h1, ListNode *h2) {
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head, ListNode *tail) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != tail) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head) {
        ListNode *pre = head, *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            cur = cur->next->next;
            pre = pre->next;
        }
        ListNode *newHead = reverse(pre, cur);
        return isSame(head, newHead);
    }
};