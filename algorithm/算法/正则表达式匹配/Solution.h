class Solution {
public:
    bool match(char* s, char* p) {
        int lens = strlen(s);
        int lenp = strlen(p);
        if (lens == 0 && lenp == 0)
            return true;
        if (lens != 0 && lenp == 0)
            return false;
        if (*(p + 1) != '*') {
            if (*s == *p || (*s != 0 && *p == '.'))
                return match(s + 1, p + 1);
            else
                return false;
        } else {
            if (*s == *p || (*s != 0 && *p == '.'))
                return match(s, p + 2) || match(s + 1, p);
            else
                return match(s, p + 2);
        }
    }
};