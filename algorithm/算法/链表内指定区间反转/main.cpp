#include <bits/stdc++.h>
#include "Solution.h"
using namespace std;

int main() {
    ListNode *p = new ListNode(0), *head = p;
    vector<int> vec({1, 2, 3, 4, 5});
    for (auto &it : vec) {
        head->next = new ListNode(0);
        head = head->next;
        head->val = it;
    }
    head = (new Solution())->reverseBetween(p->next, 2, 4);
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}