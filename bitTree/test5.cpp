// 5. 编写一个程序，构造一棵哈夫曼树，输出对应的哈夫曼编码和平均查找长度，并对表1所示的数据进行验证。
// In    0010
// The    10
// a    110
// and    0001
// are    000000
// at    01100
// be    000001
// for    01110
// he    00110
// his    01111
// is    00111
// of    010
// on    01101
// that    00001
// to    111
#include <bits/stdc++.h>
#include "huffmanTree.h"
using namespace std;
int main()
{

    HuffmanTree<string> q;
    cout << "?" << endl;
    string t;
    q.CreateBYWordsAndValue();
    q.encode(q.getRoot(), t);
    q.outputall();
    double r = q.averLen();
    cout << r << endl;
    // auto tmp = q.getRoot();
    // cout << (tmp->value);
}