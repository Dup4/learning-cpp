#ifndef LRU_H
#include <bits/stdc++.h>
using namespace std;

struct LruCache {
    struct ListNode {
        static int ptrCnt;
        int key, val;
        shared_ptr<ListNode> pre, nx;
        ListNode(int key = 0, int val = 0) : key(key), val(val) { pre = nx = nullptr; ++ptrCnt; }
        ~ListNode() {
            --ptrCnt; 
            pre.reset();
            nx.reset();
        }
    };
    map <int, shared_ptr<ListNode> > mp;
    shared_ptr<ListNode> head, tail;
    size_t k;
    LruCache(size_t k) {
        head = make_shared<ListNode>();
        tail = make_shared<ListNode>();
        head->nx = tail;
        tail->pre = head;
        this->k = k;
    }
    ~LruCache() {
        head.reset();
        tail.reset();
        for (auto &it : mp) {
            cout << it.second.use_count() << endl;
            it.second.reset();
        }
        mp.clear();
    }
    void set(int key, int value) {
        shared_ptr<ListNode> tmp(new ListNode(key, value));
        mp[key] = tmp;
        tmp->nx = head->nx;
        tmp->nx->pre = tmp;
        tmp->pre = head;
        head->nx = tmp;
        if (mp.size() > k) {
            shared_ptr<ListNode> last = mp[tail->pre->key];
            tail->pre = last->pre;
            last->pre->nx = tail;
            mp.erase(last->key);
        }
    }
    int get(int key) {
        if (mp.count(key) == 0) return -1;
        shared_ptr<ListNode> p = mp[key];
        p->pre->nx = p->nx;
        p->nx->pre = p->pre;
        p->nx = head->nx;
        head->nx->pre = p;
        p->pre = head;
        head->nx = p;
        return p->val;
    }
    void output() {
        shared_ptr<ListNode> it = head;
        it = it->nx;
        while (it != tail) {
            cout << it->key << ' ';
            it = it->nx;
        }
        cout << endl;
    }
};
int LruCache::ListNode::ptrCnt = 0;

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        shared_ptr<LruCache> lruCache(new LruCache(static_cast<size_t>(k)));
        vector <int> res;
        for (auto &op: operators) {
            if (op[0] == 1) {
                lruCache->set(op[1], op[2]);
            } else {
                res.push_back(lruCache->get(op[1]));
            }
        }
        lruCache.reset();
        cout << LruCache::ListNode::ptrCnt << endl;
        return res;
    }
};

#endif
