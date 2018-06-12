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
            // cout << tmp << endl;
            // out += ' ';
            ch = exp[cnt++];
        }
        else
        {
            S.getTop(op);
            out += ' ';
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
int suffix_value(string suffix)
{
    int len = suffix.size();
    while (suffix[0] == ' ')
    {
        suffix.erase(suffix.begin(), suffix.begin() + 1);
    }
    int i, j;
    char op;
    int stack[1000];
    int top = 0, value = 0;
    for (i = 0; suffix[i] != '\0'; i++)
    {
        if (suffix[i] >= '0' && suffix[i] <= '9')
        {
            value = value * 10 + suffix[i] - '0';
        }
        else if (suffix[i] == ' ')
        {
            if ((suffix[i - 1] != ' '))
            {
                // cout << "add " << top << "   " << value << endl;
                stack[top++] = value;
                value = 0;
            }
        }
        else
        {
            switch (suffix[i])
            {
            case '+':
                // cout << "xxxxxxxxxxxxxx " << top << endl;

                // cout << "1. " << stack[top - 2] << "   2.   " << stack[top - 1] << endl;

                value = stack[top - 2] + stack[top - 1];
                // cout << "hhh" << endl;
                break;
            case '-':
                value = stack[top - 2] - stack[top - 1];
                break;
            case '*':
                // cout << "xxxxxxxxxxxxxx " << top << endl;
                value = stack[top - 2] * stack[top - 1];
                // cout << "1. " << stack[top - 2] << "   2.   " << stack[top - 1] << endl;
                // cout << "???" << value << endl;
                break;
            case '/':
                value = stack[top - 2] / stack[top - 1];
                break;
            default:
                break;
            }
            top -= 2;
            // cout << "sub???" << endl;
            // stack[top] = value;
            // cout << "top==" << top << "   value==" << value << endl;
            // ;
        }
    }
    return stack[0];
}
int main()
{
    string str;
    str = "(13+2)*3-2-2*3";
    string m = postfix(str);
    cout << m << endl;
    // string x="13 2+ "
    cout << suffix_value(m);
    return 0;
}