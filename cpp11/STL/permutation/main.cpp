#include <bits/stdc++.h>
using namespace std;
typedef int elem_t;

/**
 * @brief 交换数组中两个元素的位置
 * @param[in] array 数组首地址
 * @param[in] 数组下标
 * @param[in] 数组下标
 * @return 无
 **/
void swap(elem_t array[], int i, int j) {
    elem_t tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/**
 * @brief 反转数组中从first位置到last位置(不包含last位置)的元素
 * @param[in] array 数组的首地址
 * @param[in] i 数组下标
 * @param[in] j 数组下标
 * @return 无
 **/
void reverse(elem_t array[], int first, int last) {
    last--;
    while (first < last) swap(array, first++, last--);
}

/**
 * @brief 返回下一个排列
 * @param[inout] num 当前排列
 * @param[in] first 开始位置
 * @param[in] last 结束位置
 * @return 成功返回0,失败返回-1
 */
int next_permutation(elem_t num[], int first, int last) {
    int i, j;
    i = last - 2; /* PartitionNumber's index */
    while (i >= 0 && num[i] >= num[i + 1]) i--;
    if (i == -1) {
        reverse(num, first, last);
        return -1;
    }
    j = last - 1;
    while (num[j] <= num[i]) --j;
    swap(num, i, j);
    reverse(num, i + 1, last);
    return 0;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    next_permutation(a, 0, 5);
    for (int i = 0; i < 5; ++i) cout << a[i] << " \n"[i == 4];
    return 0;
}