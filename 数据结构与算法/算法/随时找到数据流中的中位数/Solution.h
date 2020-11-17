#ifndef SOLUTION_H
#define SOLUTION_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Median {
        priority_queue <int, vector<int>, less<int>> maxPQ;
        priority_queue <int, vector<int>, greater<int>> minPQ;
        void add(int x) {
            if (!maxPQ.empty() && x < maxPQ.top()) {
                minPQ.push(maxPQ.top());
                maxPQ.pop();
                minPQ.push(x);
            } else {
                minPQ.push(x);
            }
            balance();
        }
        void balance() {
            while (static_cast<int>(minPQ.size() - maxPQ.size()) > 1) {
                maxPQ.push(minPQ.top());
                minPQ.pop();
            }
        }
        double get() {
            if (minPQ.empty()) return -1;
            if (maxPQ.size() == minPQ.size()) {
                return (maxPQ.top() + minPQ.top()) * 1.0 / 2;
            } else {
                return minPQ.top();
            }
        }
    };
public:
    /**
     * the medians
     * @param operations int整型vector<vector<>> ops
     * @return double浮点型vector
     */
    vector<double> flowmedian(vector<vector<int> >& operations) {
        Median *median = new Median();
        vector <double> res;
        for (auto &op : operations) {
            if (op[0] == 1) {
                median->add(op[1]);
            } else {
                res.push_back(median->get());
            }
        }
        return res;
    }
};

#endif