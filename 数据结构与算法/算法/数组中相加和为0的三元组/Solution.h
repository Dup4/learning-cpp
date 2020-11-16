class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector <vector<int>> res;
        int n = static_cast<int>(num.size());
        for (int k = 0; k < n; ++k) {
            if (num[k] > 0) break;
            if (k > 0 && num[k] == num[k - 1]) continue;
            int tmp = -num[k];
            int i = k + 1, j = n - 1;
            while (i < j) {
                if (num[i] + num[j] == tmp) {
                    res.push_back({num[k], num[i], num[j]});
                    while (i < j && num[i] == num[i + 1])
                        ++i;
                    while (i < j && num[j] == num[j - 1])
                        --j;
                    ++i;
                    --j;
                } else if (num[i] + num[j] < tmp) {
                    ++i;
                } else if (num[i] + num[j] > tmp) {
                    --j;
                }
            }
        }
        return res;
    }
};