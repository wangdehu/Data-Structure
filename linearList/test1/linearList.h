template <class T>
class LinearList
{
public:
  LinearList(){};
  virtual ~LinearList(){};
  virtual int Size() const = 0;   //表最大体积
  virtual int Length() const = 0; //表长度
  virtual int Search(T &x) const = 0;
  virtual Locate(int i) const = 0;
  virtual bool getData(int i, T &x) const = 0;
  virtual void setData(int i, T &x) = 0;
  virtual bool Insert(int i, T &x) = 0;
  virtual bool Remove(int i, T &x) = 0;
  virtual bool IsEmpty() const = 0;
  virtual bool IsFull() const = 0;
  virtual void Sort() = 0;
  virtual void Input_Front() = 0;
  virtual void Input_End() = 0;
  virtual void Output() = 0;
};
