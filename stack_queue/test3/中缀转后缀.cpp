// 利用栈对只含二目运算符的中缀算术表达式求值，
//并将该中缀表达式转换为后缀表达式。
//算术运算符包括： *、/、+、- ，优先级从高到低。
#include <iostream>
#include "SeqStack.h"
using namespace std;
int isp(char &c)
{
    switch (c)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '*':
    case '/':
    case '%':
        return 5;
    case '+':
    case '-':
        return 3;
    case ')':
        return 6;
    }
}
int icp(char &c)
{
    switch (c)
    {
    case '#':
        return 0;
    case '(':
        return 6;
    case '*':
    case '/':
    case '%':
        return 4;
    case '+':
    case '-':
        return 2;
    case ')':
        return 1;
    }
}

string postfix(const string &exp)
{
    SeqStack<char> S;
    char ch = '#', op, tmp;
    S.Push(ch);
    int len = exp.size();
    int cnt = 0;
    ch = exp[cnt++];
    // cout << "ch==" << ch << endl;
    string out;
    int num = -1;
    while (1)
    {
        S.getTop(tmp);
        // cout << tmp << endl;
        // cout << ch << endl;
        if (ch == '#' && tmp == '#')
        {
            break;
        }
        if (ch >= '0' && ch <= '9')
        {
            out += ch;
            // cout << ch << endl;
            ch = exp[cnt++];
            // if (cnt == len + 1)
            //     break;
        }
        else
        {
            S.getTop(op);
            if (icp(ch) > isp(op))
            {
                S.Push(ch);
                // cout << "111  " << ch << endl;
                ch = exp[cnt++];
                // if (cnt == len + 1)
                //     break;
                // cout << "222  " << ch << endl;
            }
            else if (icp(ch) < isp(op))
            {
                S.Pop(tmp);
                if (tmp == '#')
                {
                    break;
                }
                out += tmp;

                //  cout << tmp << endl;
            }
            else
            {
                char tmp;
                S.Pop(tmp);
                if (tmp == '(')
                {
                    ch = exp[cnt++];
                    // if (cnt == len + 1)
                    //     break;/
                }
            }
        }
    }
    return out;
}
int main()
{
    string str;
    // cin >> str;
    str = "(1+2)*3";
    string m = postfix(str);
    cout << m << endl;
    return 0;
}