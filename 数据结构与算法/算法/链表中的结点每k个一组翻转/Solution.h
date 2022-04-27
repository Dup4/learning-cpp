/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
    int getLength(ListNode *head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *pre = res, *cur = head, *tmp = nullptr;
        int length = getLength(head);
        for (int i = 0; i < length / k; ++i) {
            for (int j = 1; j < k; ++j) {
                tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
            cur = cur->next;
        }
        return res->next;
    }
};