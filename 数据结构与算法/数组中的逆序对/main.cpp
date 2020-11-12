struct Hash {
    vector <int> a;
    int size() { return static_cast<int>(a.size()); }
    void work() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    void add(int x) { a.push_back(x); }
    int get(int x) {
        return static_cast<int>(lower_bound(a.begin(), a.end(), x) - a.begin()) + 1; 
    }
};

struct BIT {
    vector <int> a;
    BIT(int n) { a = vector<int>(n, 0); }
    int size() { return static_cast<int>(a.size()); }
    void add(int x, int v) {
        for (; x < size(); x += x & -x) {
            a[x] += v;
        }
    }
    int get(int x) {
        int res = 0;
        for (; x; x -= x & -x) {
            res += a[x];
        }
        return res;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    int InversePairs(vector<int> data) {
        constexpr int mod = 1e9 + 7;
        Hash hash = Hash();
        for (auto &v : data) hash.add(v);
        hash.work();
        BIT bit = BIT(hash.size() + 1);
        int res = 0;
        for (auto &v : data) {
            v = hash.get(v);
            res = (res + bit.get(v + 1, hash.size())) % mod;
            bit.add(v, 1);
        }
        return res;
    }
};