class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int sLen = strlen(s), pLen = strlen(p);
        vector<vector<bool>> f(sLen + 1, vector<bool>(pLen + 1, true));
        for (int i = 1; i <= sLen; ++i) f[i][0] = false;
        for (int i = 0; i < pLen; ++i) {
            if (p[i] != '*') {
                for (int j = i + 1; j <= pLen; ++j) f[0][j] = false;
                break;
            }
        }
        for (int i = 1; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) {
                f[i][j] = false;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    f[i][j] = f[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j - 1] || f[i][j - 1] || f[i - 1][j];
                }
            }
        }
        return f[sLen][pLen];
    }
};