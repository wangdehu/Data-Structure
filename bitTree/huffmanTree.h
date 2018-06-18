#include <iostream>
#include <queue>
#include <vector>
#include <map>
template <class T>
struct HuffmanTreeNode
{
    bool flag;
    T pos;
    int value;
    HuffmanTreeNode<T> *lchild, *rchild;
    HuffmanTreeNode(int value, bool flag = false) : value(value), flag(flag), lchild(nullptr), rchild(nullptr) {}
    HuffmanTreeNode(T pos, int value, bool flag = true) : pos(pos), value(value), flag(flag), lchild(nullptr), rchild(nullptr) {}
};
template <class T>
struct compare
{
    bool operator()(const HuffmanTreeNode<T> *a, const HuffmanTreeNode<T> *b) const
    {
        return a->value > b->value;
    }
};
template <class T>
class HuffmanTree
{

  private:
    HuffmanTreeNode<T> *root;
    void destroy(HuffmanTreeNode<T> *tmp);
    std::map<T, std::string> res;

  public:
    HuffmanTree() {}
    ~HuffmanTree();
    double Lenall(HuffmanTreeNode<T> *tmp)
    {
        if (tmp == nullptr)
        {
            std::cout << "???" << std::endl;
            return 0;
        }
        if (tmp->lchild == nullptr && tmp->rchild == nullptr)
        {
            return (tmp->value) * (res[tmp->pos].size());
        }
        double tot = 0;
        if (tmp->lchild != nullptr)
        {
            // cout << Lenall(tmp->lchild) << endl;
            tot += Lenall(tmp->lchild);
        }
        if (tmp->rchild != nullptr)
            tot += Lenall(tmp->rchild);
        return tot;
    }
    HuffmanTreeNode<T> *getRoot() const
    {
        return root;
    }
    void CreateBYWordsAndValue();
    void encode(HuffmanTreeNode<T> *tmp, std::string s);
    void outputall()
    {
        for (auto i : res)
        {
            std::cout << i.first << "   " << i.second << std::endl;
        }
    }
};
template <class T>
HuffmanTree<T>::~HuffmanTree()
{
    destroy(root);
}
template <class T>
void HuffmanTree<T>::destroy(HuffmanTreeNode<T> *tmp)
{
    if (tmp != nullptr)
    {
        destroy(tmp->lchild);
        destroy(tmp->rchild);
        delete tmp;
    }
}
template <class T>
void HuffmanTree<T>::CreateBYWordsAndValue()
{
    int num;
    std::cout << "please input the num of words" << std::endl;
    std::cin >> num;
    std::priority_queue<HuffmanTreeNode<T> *, std::vector<HuffmanTreeNode<T> *>, compare<T>> P;
    T word;
    int value;
    for (int i = 0; i < num; ++i)
    {
        std::cin >> word >> value;
        P.push(new HuffmanTreeNode<T>(word, value));
    }
    while (P.size() > 1)
    {
        HuffmanTreeNode<T> *ptr1 = P.top();
        P.pop();
        HuffmanTreeNode<T> *ptr2 = P.top();
        P.pop();
        // std::cout << " ptr1->valu==" << ptr1->value << "   ptr2->value==  " << ptr2->value << std::endl;
        int tot = ptr1->value;
        tot += ptr2->value;
        HuffmanTreeNode<T> *tmp = new HuffmanTreeNode<T>(tot);
        tmp->lchild = ptr1;
        tmp->rchild = ptr2;

        P.push(tmp);
    }
    this->root = P.top();
}
template <class T>
void HuffmanTree<T>::encode(HuffmanTreeNode<T> *tmp, std::string s)
{
    if (tmp == nullptr)
    {
        return;
    }
    // bool f1 = tmp->lchild == nullptr ? true : false;
    // bool f2 = tmp->rchild == nullptr ? true : false;
    if (tmp->flag)
    {
        res[tmp->pos] = s;
        return;
    }
    encode(tmp->lchild, s + '0');
    encode(tmp->rchild, s + '1');
}
