class Finder {
    int Partition(vector <int> &vec, int l, int r, int k) {
        if (l == r) return vec[l];
        int _l = l, _r = r, pivot = vec[l];
        while (l < r) {
            while (l < r && vec[r] >= pivot) --r;
            vec[l] = vec[r];
            while (l < r && vec[l] <= pivot) ++l;
            vec[r] = vec[l];
        }
        vec[l] = pivot;
        if (l - _l + 1 == k) return vec[l];
        if (l - _l + 1 > k) return Partition(vec, _l, l, k);
        return Partition(vec, l + 1, _r, k - (l - _l + 1));
    }
public:
    int findKth(vector<int> a, int n, int K) {
        return Partition(a, 0, n - 1, n - K + 1);
    }
};
