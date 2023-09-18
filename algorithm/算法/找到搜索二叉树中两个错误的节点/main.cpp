/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root
     * @return int整型vector
     */
    TreeNode* pre;
    TreeNode* fi;
    TreeNode* se;
    void dfs(TreeNode* rt) {
        if (!rt)
            return;
        dfs(rt->left);
        if (pre && pre->val >= rt->val) {
            if (!fi)
                fi = pre;
            se = rt;
        }
        pre = rt;
        dfs(rt->right);
    }

    vector<int> findError(TreeNode* root) {
        // write code here
        pre = nullptr;
        fi = nullptr;
        se = nullptr;
        dfs(root);
        return {se->val, fi->val};
    }
};