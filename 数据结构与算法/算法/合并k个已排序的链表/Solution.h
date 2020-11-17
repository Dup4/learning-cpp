/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector <ListNode*>, cmp> pq;
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        for (auto &it : lists) {
            if (it != nullptr) {
                pq.push(it);
            }
        }
        while (!pq.empty()) {
            ListNode* tmp = pq.top(); pq.pop();
            p = p->next = tmp;
            if (tmp->next) {
                pq.push(tmp->next);
            }
        }
        return res->next;
        
    }
};