class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        int n = static_cast<int>(arr1.size());
        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid == n - 1) 
                return min(arr1[n - 1],arr2[0]);
            if (arr1[mid] == arr2[n - mid - 2])
                return arr1[mid];
            if (arr1[mid] < arr2[n - mid - 2]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (r < 0) {
            return min(arr1[0], arr2[n - 1]);
        }
        int a = max(arr1[l], arr2[n - 2 - l]);
        int b = max(arr1[r], arr2[n - 2 - r]);
        return min(a, b);
    }
};