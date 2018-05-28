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