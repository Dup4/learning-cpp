/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) return pHead;
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        while (pHead->next != nullptr) {
            pHead = pHead->next;
            cur->next = pre;
            pre = cur;
            cur = pHead;
        }
        cur->next = pre;
        return pHead;
    }
};
