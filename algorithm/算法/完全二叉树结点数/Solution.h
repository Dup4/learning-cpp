/**
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
    int getH(TreeNode *rt) {
        int h = 0;
        TreeNode *p = rt;
        while (p != nullptr) {
            ++h;
            p = p->left;
        }
        return h;
    }

public:
    int nodeNum(TreeNode *head) {
        if (head == nullptr)
            return 0;
        int leftH = getH(head->left);
        int rightH = getH(head->right);
        if (leftH == rightH + 1) {
            return (1 << rightH) + nodeNum(head->left);
        } else {
            return (1 << leftH) + nodeNum(head->right);
        }
    }
};