//将该中缀表达式转换为后缀表达式求值
//算术运算符包括： *、/、+、- ，优先级从高到低。

//样例: (13+2)*3-2-2*3

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
    string out;
    int num = -1;
    while (1)
    {
        S.getTop(tmp);
        if (ch == '#' && tmp == '#')
        {
            break;
        }
        if (ch >= '0' && ch <= '9')
        {
            out += ch;
            ch = exp[cnt++];
        }
        else
        {
            S.getTop(op);
            out += ' ';
            if (icp(ch) > isp(op))
            {
                S.Push(ch);
                ch = exp[cnt++];
            }
            else if (icp(ch) < isp(op))
            {
                S.Pop(tmp);
                if (tmp == '#')
                {
                    break;
                }
                out += tmp;
            }
            else
            {
                char tmp;
                S.Pop(tmp);
                if (tmp == '(')
                {
                    ch = exp[cnt++];
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
                stack[top++] = value;
                value = 0;
            }
        }
        else
        {
            switch (suffix[i])
            {
            case '+':
                value = stack[top - 2] + stack[top - 1];
                cout << stack[top - 2] << "+" << stack[top - 1] << "==" << value << endl;
                break;
            case '-':
                value = stack[top - 2] - stack[top - 1];
                cout << stack[top - 2] << "-" << stack[top - 1] << "==" << value << endl;
                break;
            case '*':
                value = stack[top - 2] * stack[top - 1];
                cout << stack[top - 2] << "*" << stack[top - 1] << "==" << value << endl;
                break;
            case '/':
                value = stack[top - 2] / stack[top - 1];
                cout << stack[top - 2] << "/" << stack[top - 1] << "==" << value << endl;
                break;
            default:
                break;
            }
            top -= 2;
        }
    }
    return stack[0];
}
int main()
{
    string str;
    cin >> str;
    string m = postfix(str);
    cout << m << endl;
    cout << "res: " << suffix_value(m);
    return 0;
}