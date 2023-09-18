/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
    int last = INT_MIN;
    bool isSearch(TreeNode* rt) {
        if (!rt)
            return true;
        bool res = isSearch(rt->left);
        if (res == false)
            return res;
        if (last > rt->val)
            return false;
        last = rt->val;
        return isSearch(rt->right);
    }
    bool flag = false;
    bool isComplete(TreeNode* rt) {
        if (!rt)
            return true;
        if (!rt->left && !rt->right)
            return true;
        if (!rt->left && rt->right)
            return false;
        if (rt->left && !rt->right) {
            if (flag)
                return false;
            flag = true;
        }
        return isComplete(rt->left) && isComplete(rt->right);
    }

public:
    /**
     *
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        return {isSearch(root), isComplete(root)};
    }
};