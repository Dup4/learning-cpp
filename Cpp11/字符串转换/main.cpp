#include <bits/stdc++.h>
using namespace std;

int main() {
    {
        // char[] 转char *
        char str[] = "str";
        char *_str = str;
        cout << str << endl;
        cout << _str << endl;
    }

    {
        // char *转换为char []
        const char *str = "str";
        char st1[] = "lalalala";
        cout << st1 << endl;
        strncpy(st1, str, strlen(str) + 1);    // 最后一位是 '\0'
        cout << st1 << endl; 
    }

    {
        // const char *转char *
        const char *st = "lala";
        // 直接赋值不可以 
        //char *st1 = st;           // （不可以编译器报错） 
        //cout << st1 << endl;
        // 另外开辟空间，将字符一个一个复制过去
        char *ncstr = new char[strlen(st) + 1];
        strcpy(ncstr, st);
        cout << ncstr << endl; 
    }

    {
        // char *转const char * 
        char *st = "hehe";         // （编译提示警告）
        const char *st1 = st;
        cout << st1 << endl;
    }

    {
        // char*转换为string
        // （注意，定义char *变量，并直接赋值，最好定义为const变量，否则编译器警告） 
        const char *st = "hello";
        // 赋值转换 
        string st1 = st;
        cout << st1 << endl;
        // 构造转换 
        string s1(st, st + strlen(st));
        cout << s1 << endl;
        // 改变const char *变量值 
        st = "lalala";
        cout << st << endl; 
    }

    {
        // string转char *
        string st = "My test";
        //char *st1 = st;           // 错误类型不同 
        //char *st1 = st.c_str();   // 错误类型不同
        char *st1 = const_cast<char *>(st.c_str()) ;
        cout << st1 << endl; 
    }

    {
        // string转char []
        string ts = "My test1";
        //char ts1[] = ts;          // 错误
        //char ts1[] = const_cast<char *>(ts.c_str());   // 错误 
        char ts1[] = "lalallalalaaaa";
        strncpy(ts1, ts.c_str(), ts.length() + 1);       // 注意，一定要加1，否则没有赋值'\0' 
        cout << ts1 << endl; 
    }
    return 0;
}