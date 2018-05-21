//写一个程序，利用KMP算法求子串t在主串是中出现的次数.
//并以s=”aaabbdaabbde”,t=“aabbd”为例，显示其匹配过程。（匹配过程的显示选做）。

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int nnext[N];
void getNext(string str)
{
    int len = str.size(), k = -1, j = 0;
    nnext[0] = -1;
    while (j < len)
    {
        if (k == -1 || str[j] == str[k])
        {
            j++, k++;
            nnext[j] = k;
        }
        else
            k = nnext[k];
    }
}
int match(string S, string P)
{
    int lenS = S.size();
    int lenP = P.size();
    int j = 0, k = 0;
    while (k < lenP && j < lenS)
    {
        cout << "p[" << k << "]==" << P[k] << endl;
        cout << "S[" << j << "]==" << S[j] << endl
             << endl;

        if (k == -1 || S[j] == P[k])
        {
            j++, k++;
        }
        else
        {
            cout << "k==" << k << "  to  " << nnext[k] << endl;
            k = nnext[k];
        }
    }
    if (k < lenP)
    {
        return -1;
    }
    else
        return j - lenP;
}
int main()
{
    string S = "aaabbdaabbde";
    string P = "aabbd";
    getNext(P);
    cout << "result : " << match(S, P);
    return 0;
}