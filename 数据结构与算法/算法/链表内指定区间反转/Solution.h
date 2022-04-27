#ifndef __SOLUTION_H__
#define __SOLUTION_H__
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val = 0) : val(val) {
        next = nullptr;
    }
};

class Solution {
    ListNode *reverse(ListNode *head, ListNode *tail) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != tail) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = tail;
        return pre;
    }

public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int l, int r) {
        if (head == nullptr)
            return nullptr;
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *leftP = res;
        ListNode *rightP = res->next;
        int p = 1;
        while (p <= r) {
            if (p < l)
                leftP = leftP->next;
            rightP = rightP->next;
            p += 1;
        }
        leftP->next = reverse(leftP->next, rightP);
        return res->next;
    }
};

#endif