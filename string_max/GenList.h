#include <cstdlib>
template <class T>
struct Items
{

    int utype;
    union {
        int ref;
        T value;
        GenLinkNode<T> *hlink;
    } info;
    Items() : utype(0), info.ref(0) {}
    Items(Items<T> &RL)
    {
        utype = RL.utype;
        info = Rl.info;
    }
};
template <class T>
struct GenLinkNode
{
    int utype;
    union {
        int ref;
        T value;
        GenLinkNode<T> *hlink;
    } info;
    GenLinkNode<T> *tlink;
    GenLinkNode() : utype(0), info.ref(0), tlink(nullptr) {}
    GenLinkNode(GenLinkNode<T> &RL)
    {
        utype = RL.utype;
        info = Rl.info;
    }
};
template <class T>
class GenList
{
  public:
    GenList();
    ~GenList();
    bool Head(Items &x);
    bool Tail(GenList<T> &lt);
    GenLinkNode<T> *First();
    GenLinkNode<T> *Next(GenLinkNode<T> *elem);
    void Copy(const GenList<T> &R);
    int Length();
    int Depth();

    // friend istream &operator>>(istream &in, GenList<T> &L);

  private:
    GenLinkNode<T> *first;
    GenLinkNode<T> *Copy(GenLinkNode<T> *ls);
    int Length(GenLinkNode<T> *ls);
    int Depth(GenLinkNode<T> *ls);
    bool equal(GenLinkNode<T> *s, GenLinkNode<T> *t);
    void Remove(GenLinkNode<T> *ls);
    void Createlist(istream &in, GenLinkNode<T> *&ls);
};
template <class T>
GenList<T>::GenList()
{
    first = new GenLinkNode;
    assert(first != nullptr);
}
template <class T>
GenList<T>::~GenList()
{
    Remove(first);
}
template <class T>
bool GenList<T>::Head(Items<T> &x)
{
    if (first->tlink == nullptr)
    {
        return fasle;
    }
    else
    {
        x.utype = first->tlink->utype;
        x.info = first->tlink->info;
        return true;
    }
}
template <class T>
bool GenList<T>::Tail(GenList<T> &lt)
{

    if (first->tlink == nullptr)
    {
        return fasle;
    }
    else
    {
        lt.first->utype = 0;
        lt.first->info.ref = 0;
        lt.first->tlink = Copy(first->tlink->tlink);
        return true;
    }
}
template <class T>
GenLinkNode<T> *GenList<T>::First()
{
    if (first->tlink == nullptr)
    {
        return nullptr;
    }
    else
    {
        return first->tlink;
    }
}
template <class T>
GenLinkNode<T> *GenList<T>::Next(GenLinkNode<T> *elem)
{
    if (elem->tlink == nullptr)
    {
        return nullptr;
    }
    else
    {
        return elem->tlink;
    }
}
template <class T>
int GenList::Length()
{
    return Length(this);
}
template <class T>
int GenList::Length(GenLinkNode<T> *ls)
{
    if (ls != nullptr)
    {
        return Length(ls->tlink) + 1;
    }
    else
    {
        return 0;
    }
}
template <class T>
int GenList::Depth()
{
    return Depth(this);
}
template <class T>
int GenList::Depth(GenLinkNode<T> *ls)
{
    if (ls->tlink == nullptr)
    {
        return 1;
    }
    GenLinkNode<T> *temp = ls->tlink;
    int m = 0, n;
    while (temp != nullptr)
    {
        if (temp->utype == 2)
        {
            n = Depth(temp->info.hlink);
            if (m < n)
                m = n;
        }
        temp = temp->tlink;
    }
    return m + 1;
}
template <class T>
void GenList::Copy(const GenList<T> &R)
{
    first = Copy(R.first);
}
template <class T>
GenLinkNode<T> *GenList::Copy(GenLinkNode<T> *ls)
{
    GenLinkNode<T> *q = nullptr;
    if (ls != nullptr)
    {
        q = new GenLinkNode<T>;
        q->utype = ls->utype;
        switch (ls->utype)
        {
        case 0:
            q->info.ref = ls->info.ref;
            break;
        case 1:
            q->info.value = ls->info.value;
            break;
        case 2:
            q->info.hlink = ls->info.hlink;
            break;
        }
        q->tlink = Copy(ls->tlink);
    }
    return q;
}
template <class T>
bool GenList::equal(GenLinkNode<T> *s, GenLinkNode<T> *t)
{
    int x;
    if (s->tlink == nullptr && t->tlink == nullptr)
    {
        return true;
    }
    if (s->tlink != nullptr && t->tlink != nullptr && s->tlink->utype == t->tlink->utype)
    {
        if (s->tlink->utype == 1)
            x = (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;
        else if (s->tlink->utype == 2)
            x = equal(s->tlink->info.hlink, t->tlink->info..hlink);
        if (x == 1)
        {
            return equal(s->tlink, t->tlink);
        }
    }
    return false;
}
template <class T>
void GenList::Remove(GenLinkNode<T> *ls)
{
    ls->info.ref--;
    if (ls->info.ref <= 0)
    {
        GenLinkNode<T> *q;
        while (ls->tlink != nullptr)
        {
            q = ls->tlink;
            if (q->utype == 2)
            {
                Remove(q->info.hlink);
                if (q->info.hlink - info.ref <= 0)
                {
                    delete q->info.hlink;
                }
            }
            ls->tlink = q->tlink;
            delete q;
        }
    }
}
// template <class T>
// void Genlist<T>::Createlist(istream &in, GenLinkNode<T> *&ls)
// {

// }
