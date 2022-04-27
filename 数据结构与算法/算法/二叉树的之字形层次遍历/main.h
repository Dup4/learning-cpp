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
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        int f = 0;
        while (!que.empty()) {
            int sze = static_cast<int>(que.size());
            vector<int> vec;
            for (int _ = 0; _ < sze; ++_) {
                TreeNode* rt = que.front();
                que.pop();
                vec.push_back(rt->val);
                if (rt->left != nullptr)
                    que.push(rt->left);
                if (rt->right != nullptr)
                    que.push(rt->right);
            }
            if (f)
                reverse(vec.begin(), vec.end());
            res.push_back(vec);
            f ^= 1;
        }
        return res;
    }
};