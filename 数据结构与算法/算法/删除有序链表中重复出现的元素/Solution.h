/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* pre = res;
        ListNode* p = res;
        while (head) {
            if (p == nullptr || p->val != head->val) {
                pre = p;
                p = p->next = head;
                head = head->next;
            } else {
                p = pre;
                p->next = nullptr;
                int tmp = head->val;
                while (head && head->val == tmp) head = head->next;
            }
        }
        return res->next;
    }
};