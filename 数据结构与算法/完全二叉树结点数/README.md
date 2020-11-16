# 完全二叉树结点数

[提交链接](https://www.nowcoder.com/practice/512688d2ecf54414826f52df4e4b5693?tpId=117&&tqId=35006&rp=1&ru=/ta/job-code-high&qru=/ta/job-code-high/question-ranking)


## 思路

- 考虑高度为 $h$ 的满二叉树的结点个数为 $2^h - 1$。
- 对于当前子树来说:
  - 如果左子树的深度为右子树深度 +1, 那么右子树是一个满二叉树。
  - 如果深度相等，那么左子树是一个满二叉树。
