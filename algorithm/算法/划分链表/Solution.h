#ifndef SOLUTION_H
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
public:
    /**
     *
     * @param head ListNode类
     * @param x int整型
     * @return ListNode类
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *pSmall = nullptr, *pSmallHead = nullptr;
        ListNode *pLarge = nullptr, *pLargeHead = nullptr;
        while (head != nullptr) {
            if (head->val < x) {
                if (pSmallHead == nullptr) {
                    pSmallHead = pSmall = head;
                } else {
                    pSmall = pSmall->next = head;
                }
            } else {
                if (pLargeHead == nullptr) {
                    pLargeHead = pLarge = head;
                } else {
                    pLarge = pLarge->next = head;
                }
            }
            head = head->next;
        }
        if (pLarge != nullptr)
            pLarge->next = nullptr;
        if (pSmallHead == nullptr)
            return pLargeHead;
        pSmall->next = pLargeHead;
        return pSmallHead;
    }
};

#endif