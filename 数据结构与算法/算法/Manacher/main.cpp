#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e7 + 10;
char s[N];

struct Manacher {
    int Mp[N << 1];
    char Ma[N << 1];
    int gao(char *s) {
        int len = strlen(s);
        int l = 0;
        Ma[l++] = '$';
        Ma[l++] = '#';
        for (int i = 0; i < len; ++i) {
            Ma[l++] = s[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for (int i = 0; i < l; ++i) {
            Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
            while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) ++Mp[i];
            if (i + Mp[i] > mx) {
                mx = i + Mp[i];
                id = i;
            }
        }
        int res = 0;
        for (int i = 0; i < l; ++i) {
            res = max(res, Mp[i] - 1);
        }
        return res;
    }
} manacher;

int main() {
    scanf("%s", s);
    printf("%d\n", manacher.gao(s));
    return 0;
}
