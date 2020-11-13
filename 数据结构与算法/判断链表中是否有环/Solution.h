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
    bool hasCycle(ListNode *head) {
        ListNode* one;
        ListNode* two;
        one = head;
        two = head;
        while (one || two) {
            one = one->next;
            if (two) two = two->next;
            else return false;
            if (two) two = two->next;
            else return false;
            if (one == two) return true;
        }
        return false;
    }
};