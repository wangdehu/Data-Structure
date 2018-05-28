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
    HuffmanTreeNode(int value, bool flag = false) : value(value), flag(flag) {}

    HuffmanTreeNode(T pos, int value, bool flag = true) : pos(pos), value(value), flag(flag) {}
    // bool operator<(const HuffmanTreeNode &other) const
    // {
    //     return value < other.value;
    // }
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
    HuffmanTree()
    {
    }
    ~HuffmanTree();

    // CreateBystring(string str);
    double averLen()
    {
        int cnt = res.size();
        double tot = 0;
        for (auto i : res)
        {
            tot += i.second.size();
        }
        double r = double(tot) / cnt;
        return r;
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
// template <class T>
// HuffmanTree::HuffmanTree()
// {
// }
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
    // std::priority_queue<Node*, std::vector<Node*>, compare> q;

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
        // std::cout << P.size() << std::endl;
        HuffmanTreeNode<T> *ptr1 = P.top();
        P.pop();
        HuffmanTreeNode<T> *ptr2 = P.top();
        P.pop();
        std::cout << " ptr1->valu==" << ptr1->value << "   ptr2->value==  " << ptr2->value << std::endl;
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
    std::cout << "111" << std::endl;
    if (tmp == nullptr)
    {
        std::cout << "1112" << std::endl;

        return;
    }
    std::cout << "112" << std::endl;

    bool f1 = tmp->lchild == nullptr ? true : false;
    bool f2 = tmp->rchild == nullptr ? true : false;
    std::cout << "113" << std::endl;
    if (tmp->flag)
    {
        res[tmp->pos] = s;
        std::cout << "uuu" << std::endl;
        return;
    }
    std::cout << "114" << std::endl;
    encode(tmp->lchild, s + '0');
    std::cout << "115" << std::endl;
    encode(tmp->rchild, s + '1');
    std::cout << "116" << std::endl;
}
