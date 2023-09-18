class Solution {
    int Partition(vector<int> &A, int l, int r) {
        int pivot = A[l];
        while (l < r) {
            while (l < r && A[r] >= pivot) --r;
            A[l] = A[r];
            while (l < r && A[l] <= pivot) ++l;
            A[r] = A[l];
        }
        A[l] = pivot;
        return l;
    }

    void QuickSort(vector<int> &vec, int l, int r) {
        if (l >= r)
            return;
        int pos = Partition(vec, l, r);
        QuickSort(vec, l, pos - 1);
        QuickSort(vec, pos + 1, r);
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int> &arr) {
        QuickSort(arr, 0, arr.size() - 1);
        return arr;
    }
};
