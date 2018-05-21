// 1.	采用顺序存储结构存储串，编写一个程序.
// 采用简单模式匹配方法求串s中出现的第一个最长重复子串的下标和长度。
// 例如：s=“aababcabcdabcde”，最长重复子串为：abcd

#include <bits/stdc++.h>
#include <map>
using namespace std;
int main()
{
    string s = "aababcabcdabcde";
    int len = s.size();
    map<string, bool> o;
    int maxn = -1;
    string s2;
    for (int i = 0; i < len; ++i)
    {
        string tmp;
        for (int j = 0; j + i < len; ++j)
        {
            tmp += s[i + j];
            if (o[tmp] == false)
            {
                o[tmp] = true;
            }
            else
            {
                int len2 = tmp.size();
                if (len2 > maxn)
                {
                    maxn = tmp.size();
                    s2 = tmp;
                }
            }
        }
    }
    cout << s2 << endl;
    return 0;
}