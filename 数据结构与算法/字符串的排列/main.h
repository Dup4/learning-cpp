class Solution {
    vector <string> res;
    void dfs(string str, int iLen, int iStart) {
        if (iLen == iStart) {
            res.push_back(str);
        } else {
            for(int j = iStart; j < iLen; ++j) {
                if (j != iStart && str[j] == str[iStart]) continue;
                swap(str[iStart], str[j]);
                dfs(str, iLen, iStart + 1);
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        if (str.empty()) return {};
        dfs(str, static_cast<int>(str.size()), 0);
        return res;
    }
};