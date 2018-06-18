// 5. 编写一个程序，构造一棵哈夫曼树，输出对应的哈夫曼编码和平均查找长度，并对表1所示的数据进行验证。
// 15
// In    450
// The    1192
// a    541
// and    462
// are    124
// at    181
// be    123
// for    157
// he    195
// his    138
// is    190
// of    677
// on    174
// that    242
// to    518
#include <bits/stdc++.h>
#include "huffmanTree.h"
using namespace std;
int main()
{
    HuffmanTree<string> q;
    q.CreateBYWordsAndValue();
    cout << endl;
    q.encode(q.getRoot(), "");
    q.outputall();
    cout << endl;
    q.encode(q.getRoot(), "");
    q.outputall();
    double r = q.Lenall(q.getRoot()) / q.getRoot()->value;
    cout << fixed << "average find number: " << r << endl;
    return 0;
}