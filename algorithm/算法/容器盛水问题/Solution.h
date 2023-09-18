class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        if (n < 3)
            return 0;
        int l = 0, r = n - 1;
        int wl = arr[0], wr = arr[n - 1];
        long long sum = 0;
        while (l <= r) {
            if (arr[l] < arr[r]) {
                if (arr[l] < wl)
                    sum += wl - arr[l];
                else
                    wl = arr[l];
                ++l;
            } else {
                if (arr[r] < wr)
                    sum += wr - arr[r];
                else
                    wr = arr[r];
                --r;
            }
        }
        return sum;
    }
};