#include <bits/stdc++.h>
#include "Solution.h"
using namespace std;

int main() {
    ListNode *p = nullptr, *head = nullptr;
    vector <int> vec({1, 4, 3, 2, 5, 2});
    for (auto &it : vec) {
        if (!p) head = p = new ListNode(it);
        else {
            p->next = new ListNode(it);
            p = p->next;
        }
    }
    p = (new Solution())->partition(head, 3);
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
    return 0;
}