<!-- TOC -->

- [**摘要**：](#摘要)
- [完成情况概述：](#完成情况概述)
- [第一题：用单链表实现大整数相加](#第一题用单链表实现大整数相加)
- [第二题：约瑟夫环问题](#第二题约瑟夫环问题)
- [第三题：中缀表达式转换后缀表达式并求值](#第三题中缀表达式转换后缀表达式并求值)
- [第四题：字符串的模式匹配(KMP)](#第四题字符串的模式匹配kmp)
- [第五题：huffman 树的实现及编码](#第五题huffman-树的实现及编码)
- [第六题：最短路算法](#第六题最短路算法)
- [第七题：最小生成树算法](#第七题最小生成树算法)
- [第八题：快速排序算法及其改进](#第八题快速排序算法及其改进)
- [总结](#总结)

<!-- /TOC -->

## **摘要**：

数据结构是计算机科学与技术专业的核心课程之一，其重要程度不用过多叙述。而我校开设该课程的时间与其他学校相比较而言略微有些迟(大二下)，不过随着课程改革，将数据结构课程设计作为一门单独的课程，还是提升了不少的学习效率。在这个学期的学习后，还是非常有收获的，尤其更加了解了各种数据结构的本质，在过去的基础上更加系统化，条理化。

## 完成情况概述：

以下项目未完成(必做+选作)：
|**章节**|**题号**|**必做/选作**|
|:-|:-|:-|
|第三章| 4|必做|
|第四章| 3|选作|
|第四章| 4|必做|
|第四章| 实训 1|必做|
|第五章| 5|必做|
|第五章|实训 1|选作|
|第五章|实训 2|选作|
|第六章| 3|必做|

## 第一题：用单链表实现大整数相加

**问题概述:**
用单链表实现两个大整数相加运算。

1.  将用户输入的十进制整数字符串转化为带头结点的单链表，每个结点存放一个整数位。
2.  求两个整数单链表相加的结果单链表
3.  求结果单链表的中间位，如 234 的中间位是“3”，2345 的中间位是“3”。

**需求分析:**

1.  将用户的输入的大整数使用单链表存储，因为大数所以采用字符串暂时存储。即 将一个字符串数字按位保存在单链表中。
2.  考虑到单链表相加的特性，所以低位数字放在靠近附加头节点的一端
3.  相加的时候按照加法规则，诸位相加，同时考虑进位的问题。
4.  暂时不考虑负数的问题

**概要设计：**

- 实现函数 1：可以将字符串数字转换位单链表

  > 函数名称：List<int\> \*getList(string str)<br>
  > 功能描述: 根据字符串大数求 List  
  > 参数列表: str 字符串大数  
  > 返回结果：返回得到的 List 指针（List<int\> \*）

- 实现函数 2：可以实现两个表示大数的单链表相加

  > 函数名称：List<int\> *add(List<int> *Ba, List<int> \*Bb)<br>
  > 功能描述: 实现两个表示大数的单链表相加<br>
  > 参数列表: 表示大数的单链表 Ba,Bb  
  > 返回结果：返回指向相加的结果的指针（List<int\> \*）

- 实现函数 3：可以得到单链表的中值

  > 函数名称：int outputMid(List<int\> \*t)<br>
  > 功能描述: 得到制定单链表的中值<br>
  > 参数列表: 表示大数的单链表 t<br>
  > 返回结果：返回中值结果（int)

- 时间复杂度分析：
  > 假设两个数字的长度分别位 N 与 M<br>
  > 则有 O(N)+O(M)+O(max(M,N))+O(max(M,N)/2)<br>
  > 总复杂度 O(Max(N,M))

**详细设计：**

```cpp
int outputMid(List<int> *t)
{
    int posc = (t->Length() + 1) / 2;
    return t->Locate(posc)->data;
}
List<int> *add(List<int> *Ba, List<int> *Bb)
{
    LinkNode<int> *Nodea = Ba->getHead();
    LinkNode<int> *Nodeb = Bb->getHead();
    List<int> *Bc = new List<int>;
    bool flag = false;
    while (Nodea->link != nullptr && Nodeb->link != nullptr)
    {
        int ta = Nodea->link->data;
        int tb = Nodeb->link->data;
        if (flag)
            ta++;
        if (ta + tb >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, (ta + tb) % 10);
        Nodea = Nodea->link;
        Nodeb = Nodeb->link;
    }
    while (Nodea->link != nullptr)
    {
        int temp = Nodea->link->data;
        if (flag)
            temp++;
        if (temp >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, temp % 10);
        Nodea = Nodea->link;
    }
    while (Nodeb->link != nullptr)
    {
        int temp = Nodeb->link->data;
        if (flag)
            temp++;
        if (temp >= 10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        Bc->Insert(0, temp % 10);
        Nodeb = Nodeb->link;
    }
}
List<int> *getList(string str)
{
    List<int> *B = new List<int>;
    int lena = str.size();
    for (int i = 0; i < lena; ++i)
    {
        int temp = str[i] - '0';
        B->Insert(0, temp);
    }
    return B;
}
```

**调试分析：**

| **Input_Ba** | **Input_Bb** | **Output_Bc** | **Output_2** |
| :----------- | :----------- | :------------ | :----------- |
| 11111        | 22222        | 33333         | 3            |
| 11111        | 12345        | 23456         | 4            |
| 12           | 399          | 411           | 1            |

**结论与展望：**

结论：

当 C++内置类型无法描述足够大的数据时，可以线性表存储大数，并可在其上完成对一些操作比如加法的封装。在这里使用了单链表，实际上使用顺序存储结构也可以。

展望：

1.  在每个节点上并不一定只存储 1 位，这样对空间的浪费很大，可以选择较大的数字作为基数比如 1e9+7.
2.  在上面的实现中，暂时只针对正数。考虑将正负信息存储在附加头节点中。
3.  可以考虑加入+-\*/%5 种常用数字计算操作

---

<br>

## 第二题：约瑟夫环问题

**问题概述:**

约瑟夫环是一个数学的应用问题：已知 n 个人（以编号 1，2，3...n 分别表示）围坐在一张圆桌周围。从编号为 k 的人开始报数，数到 m 的那个人出列；他的下一个人又从 1 开始报数，数到 m 的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。对输入的 n,m 求出出列序列直到只剩下一个人。

**需求分析:**

1.  循环链表来作为整体代码的实现
2.  进行 n-1 次循环，每次出列一个人
3.  在每次循环中，通过循环链表进行 m 次转移
4.  如果循环队列是带有附加头的，则当转移至附加头时，自动向后转移

**概要设计：**

- 实现函数 1 :将 n 个人的序号节点有序加入链表中，并使一号作为附加头节点的 link 结点

  > 函数名称：void init(int n, CircList<int\> \*l) <br>
  > 功能描述: 1~n 号入队 <br>
  > 参数列表: n， 指向 root 的指针<br>
  > 返回结果：void

- 实现函数 2 :转移 m 次，出队一人

  > 函数名称：void Popone(CircList<int\> _l, int m, CircLinkNode<int\> _&pre, CircLinkNode<int\> \*&first) <br>
  > 功能描述: 根据 pre 与 first，出队一人 <br>
  > 参数列表: 循环链表 l,出队间隔 m,之前出队指向的节点，循环链表的附加头节点 <br>
  > 返回结果：void

- 时间复杂度分析：

  > 函数 1 时间复杂度位 O(n) <br>
  > 函数 2 时间复杂度 O(m) <br>
  > 总时间复杂度 O(n)+O(m\*(n-1)) 即 O(n\*m) <br>

**详细设计：**

```cpp
void init(int n, CircList<int> *l)
{
    for (int i = n; i >= 1; --i)
    {
        l->Insert(0, i);
    }
}
void Popone(CircList<int> *l, int m, CircLinkNode<int> *&pre, CircLinkNode<int> *&first)
{
    int tmp = m;
    while (tmp--)
    {
        pre = pre->link;
        if (pre == first)
        {
            pre = pre->link;
        }
    }
    cout << pre->data << " be out " << endl;
    int uu;
    l->Remove(l->Search(pre->data), uu);
}
```

**调试分析：**

| **Input_n** | **Input_m** | **Output**    |
| :---------- | :---------- | :------------ |
| 2           | 2           | 2             |
| 5           | 2           | 2 4 1 5       |
| 8           | 3           | 3 6 1 5 2 8 4 |

**结论与展望：**

结论：

在借助循环链表的情况下，可以很简单的完成约瑟夫环的问题，只需要进行一次 n 个人的入队，然后 n-1 次出队即可。值得注意的是附加头节点不代表任何一个人，当转移到它时，需要将他转移到下一位。

展望：

1.  在上面的过程中，我们实际上进行的是模拟了全部的游戏过程，耗时较大并且占用了 n 的空间。
2.  实际上，解决约瑟夫环还有数学递推的方式，在每次出队后，并且游戏还没有结束这时是一个新的约瑟夫环问题。不过相对于上一次，编号做了转移，可以借此作为出发点尝试推倒。不过这种方法和数据结构关系不大，故不做研究

---

## 第三题：中缀表达式转换后缀表达式并求值

**问题概述:**

利用栈将中缀表达式转换为后缀表达式并求值。
算术运算符包括：\*、/、+、-，优先级从高到低。

**需求分析:**

1.  中缀转后缀的方式需要借助栈来暂存操作数与操作符
2.  在转换过程需要考虑各种操作符的优先性
3.  为了简化问题，需要加入特殊字符，此处使用#

**概要设计：**

- 实现函数 1 :不同操作符与其栈内优先数的对应

  > 函数名称：int isp(char &c) <br>
  > 功能描述: 不同操作符与其栈内优先数的对应 <br>  
  > 参数列表: 字符 c ( (#+-\*/() ) <br>
  > 返回结果：栈内优先数(int)

- 实现函数 2 :不同操作符与其栈外优先数的对应

  > 函数名称：int icp(char &c) <br>
  > 功能描述: 不同操作符与其栈外优先数的对应 <br>
  > 参数列表: 字符 c ( (#+-\*/() ) <br>
  > 返回结果：栈外优先数(int)

- 实现函数 3 :中缀表达式转换为后缀表达式

  > 函数名称：string postfix(const string &exp) <br>
  > 功能描述: 中缀表达式转换为后缀表达式 <br>
  > 参数列表: string 中缀表达式 <br>
  > 返回结果：string 后缀表达式

- 实现函数 4 :后缀表达式求值

  > 函数名称：int icp(char &c) <br>
  > 功能描述: 后缀表达式求值 <br>
  > 参数列表: string 后缀表达式 <br>
  > 返回结果：求值结果(int)

- 时间复杂度分析：

  > 函数 1 时间复杂度位 O(1) <br>
  > 函数 2 时间复杂度 O(1) <br>
  > 函数 3 时间复杂度位 O(n) <br>
  > 函数 4 时间复杂度 O(n) <br>
  > 总时间复杂度 O(n)

  部分算法描述如下：
  （中缀转后缀）

  1.  操作符栈初始化，将结束符#进栈。然后读人中缀表达式字符流的首字符 ch.
  2.  重复执行以下步骤,直到 ch='#',同时栈顶的操作符也是‘#’，停止循环。
      1.  若 ch 是操作数直接输出，读人下一个字符 ch.
      2.  若 ch 是操作符.判断 ch 的优先级 icp 和当前位于栈顶的操作符 op 的优先级 isp
          - 若 icp(ch) > isp(op),令 ch 进栈，读人下一个字符 ch.
          - 若 icp(ch) < isp(op)，退栈并输出。
          - 若 icp(ch)==isp(op),退栈但不输出，若退出的是(号读人下一字 ch
      3.  算法结束.输出序列即为所需的后级表达式

**详细设计：**

```cpp
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
```

**调试分析：**

| **Input**      | **Output_suffix**      | **Output_res** |
| :------------- | :--------------------- | :------------- |
| (13+2)*3-2-2*3 | 13 2 + 3 _ 2 - 2 3 _ - | 37             |
| (3+2)*(1*5)    | 3 2 + 1 5 \* \*        | 25             |
| (3+6)/(4-1)    | 3 6 + 4 1 - /          | 3              |

**结论与展望：**

结论：

在借助栈的情况下实现了中缀表达式求后缀表达式，在这个过程中，隐含了加括号的优先顺序，这样便方便了后续对后缀表达式的计算。

展望：

1.  中缀转为后缀时，为了配合后续求值所以数字之间使用空格隔开，以及还有些格式控制上，在代码上难以修改，在美观上较为不足
2.  在后缀运算过程中产生的负数可以处理，但是无法处理初始值中就含有负数的情况，需要改进
3.  在求各个算术运算符的优先级时，不停的使用了函数，这样降低了效率，应该将字符与数字做映射或者进行函数内联来节省时间

---

## 第四题：字符串的模式匹配(KMP)

KMP 算法是一种改进的字符串匹配算法，由 D.E.Knuth，J.H.Morris 和 V.R.Pratt 同时发现，因此人们称它为克努特——莫里斯——普拉特操作（简称 KMP 算法）。KMP 算法的关键是利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。一般匹配字符串时，我们从目标字符串 S（假设长度为 n）的第一个下标选取和 P 长度（长度为 m）一样的子字符串进行比较，如果一样，就返回开始处的下标值，不一样，选取 S 下一个下标，同样选取长度为 n 的字符串进行比较，直到 S 的末尾（实际比较时，下标移动到 n-m）。这样的时间复杂度是 O(n\*m)。KMP 算法可以实现上述操作的复杂度为 O(m+n)

**问题概述:**

给出两个字符串 S 与 P,要求确认 P 是不是 S 的子串,若是则求出它第一次出现的位置.

**需求分析:**

1.  在学习 Kmp 算法过程中，我们必须理解 next 数组的作用
2.  Next[i]表示子串 P[0~i-1]的最长公共前缀后缀长度

**概要设计：**

- 实现函数 1 :求出指定字符串的 Next 数组

  > 函数名称：void getNext(string str) <br>
  > 功能描述: 求出指定字符串的 Next 数组 <br>  
  > 参数列表: 字符串 P （string) <br>
  > 返回结果：void

- 实现函数 2 :对两串进行模式匹配，求出 P 串在 S 中第一次出现的位置

  > 函数名称：int match(string S, string P) <br>
  > 功能描述: 对两串进行模式匹配，求出 P 串在 S 中第一次出现的位置
  > 参数列表: 字符 c ( (#+-\*/() ) <br>
  > 返回结果：匹配的位置

- 时间复杂度分析

  > 设 P 串的长度为 N，S 串的长度为 M <br>
  > 函数 1 时间复杂度 O(N) <br>
  > 函数 2 时间复杂度 O(M) <br>
  > 总复杂度 时间复杂度 O(N+M)

部分算法说明:
S 串:acabaabaabcacaabc
P 串:abaabcac

然后引入两个变量,可以理解为当前要比较字符的 S 串和 P 串中的位置.
J 与 K(J=0,K=0)

![alt](https://www.wrzzing.cn/static/upload/20180414/upload_af2304b5393fa3902443c9f7ae94a04c.png)

然后规则如下:

进行若干趟匹配,当 P 串首字母与 S 串相匹配的位置改变为一趟.

len(P)为 P 串长度

1.  若是 S[J]==P[K],则单个字符匹配成功,J++,K++.
2.  若是 S[J]!=P[K],则单个字符匹配失败:
    - 若已经匹配的长度!=0 ,则 J 不变,K=(已经匹配的长度-已经匹配串最的大相同前缀后缀长)
    - 若已经匹配的长度==0 ,则 J++,K=(已经匹配的长度-已经匹配串的最大相同前缀后缀长)
3.  单个字符匹配,直到 K==len(P),则匹配成功.结果为 J 的结束值-K.

第一趟:

> 1.a=a(J=0,K=0)

> 2.c!=b(J=1,K=1)
> 匹配失效 情景一:
> J 不变,K=(已经匹配的长度-已经匹配串的最大相同前缀后缀长)=1-1=0
> =>J=1,K=0

第二趟:

> 1.c!=a(J=1,K=0)

匹配失效 情景二:
J++,K=(已经匹配的长度-已经匹配串的最大相同前缀后缀长)=0-0=0
=>J=2,K=0

第三趟:

> 1.a=a(J=2,K=0)

> 2.b=b(J=3,K=1)

> 3.a=a(J=4,K=2)

> 4.a=a(J=5,K=3)

> 5.b=b(J=6,K=4)

> 6.a!=c(J=7,K=5)

匹配失效 情景一:
J 不变,K=(已经匹配串的长度-已经匹配串最大相同前缀后缀长)=5-2=3
=>J=7,K=3

第四趟:

> 1.a=a(J=8,K=3)

> 2.a=a(J=9,K=4)

> 3.b=b(J=10,K=5)

> 4.c=c(J=11,K=6)

> 5.a=a(J=12,K=7)

> 6.c=c(J=13,K=8)

匹配成功 ,结果为 J-K=13-8=5

该样例的过程就是这样.然后我们要说明这个,已经匹配串的最大相同前缀后缀长的求解方法,其中的数据保存在一个数组中,一般称作 next 数组

定义 next 数组如下,对长度为 N 的字符串 P:
![alt](https://www.wrzzing.cn/static/upload/20180414/upload_b7d0f71f52eb2f22ab916b00bf782e5d.png)

这个已经匹配串当然是 P 串的一个前缀串,采用线性从前向后扫描的形式,求解 next 数组.可以理解为逐个添加字符到末尾.

在原理上,和前文使用它的时候很是类似.也是在利用已经得到的的 next 数组.

![alt](https://www.wrzzing.cn/static/upload/20180414/upload_39177c5dae827439fcd8e600c14706e0.png)

参考如下定义:

![alt](https://www.wrzzing.cn/static/upload/20180414/upload_278dc9d930345f098a5d860cc6391250.png)

从上面的图中,我们可以推理出一些信息,A=B=C=D,E=F

c 与 G 的关系等同于 b 与 E 等同于 a 与 A

对于 G,我们已经知道了加入各个字符后的 next 值,然后我们开始考虑加入字符 c.

1.  若是 c\=\=b ,则 E+b\=\=F+c,最长公共前缀后缀串的长 next[pos[c]+1]=next[pos[c]]+1
2.  若是 c!=b ,则考虑从 F 中找出一个后缀(!=F),从 E 中找出一个前缀(!=E)相等,又 E=F,则寻找 E 中的最长公共前缀后缀串,这个值已经在加入 b 的时候计算过了.则该前缀为 A,后缀为 D. - 若是 A+a==D+c,则最长公共前缀后缀 next[pos[c]+1]=next[pos[a]]+1 - 若是 A+a!=D+c,则可将 a 视做 b,A 视做 E,D 视作 F,继续该操作 - ... - 无法找到相等的前缀后缀时,则比较首字母与 c,有 next[pos[c]+1]=(P[0]==c)?1:0

**详细设计：**

```cpp
const int N = 1e5 + 10;
int nnext[N];
void getNext(string str)
{
    int len = str.size(), k = -1, j = 0;
    nnext[0] = -1;
    while (j < len)
    {
        if (k == -1 || str[j] == str[k])
        {
            j++, k++;
            nnext[j] = k;
        }
        else
            k = nnext[k];
    }
}
int match(string S, string P)
{
    int lenS = S.size();
    int lenP = P.size();
    int j = 0, k = 0;
    while (k < lenP && j < lenS)
    {
        cout << "p[" << k << "]==" << P[k] << endl;
        cout << "S[" << j << "]==" << S[j] << endl
             << endl;
        if (k == -1 || S[j] == P[k])
        {
            j++, k++;
        }
        else
        {
            cout << "k==" << k << "  to  " << nnext[k] << endl;
            k = nnext[k];
        }
    }
    if (k < lenP)
    {
        return -1;
    }
    else
        return j - lenP;
}
```

**调试分析：**

| **Input_P**       | **Input_S** | **Output** |
| :---------------- | :---------- | :--------- |
| acabaabaabcacaabc | abaabcac    | 5          |
| bbcabcdababcdabd  | bcdaba      | 4          |

**结论与展望：**

结论:

KMP 算法是一种改进的字符串匹配算法，利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。其复杂度远低于朴素匹配，仅仅只有 O(N+M)

展望：

1.  在字符串的相关算法中，KMP 的思想得到广泛的利用，比如扩展 KMP 算法，AC 自动机等算法。所以 KMP 算法至关重要，其简单高效的特征也应当是我们任何时候的追求
2.  KMP 算法其实还可以在进行一项小的优化，在这里不做更多的讨论。

---

## 第五题：huffman 树的实现及编码

**问题概述:**

哈夫曼编码(Huffman Coding)，又称霍夫曼编码，是一种编码方式，哈夫曼编码是可变字长编码(VLC)的一种。Huffman 于 1952 年提出一种编码方法，该方法完全依据字符出现概率来构造异字头的平均长度最短的码字，有时称之为最佳编码，一般就叫做 Huffman 编码（有时也称为霍夫曼编码）。给定单词以及其出现频数，输出对应的 huffman 编码以及平均长度

**需求分析:**

1.  Huffman 树的实现手段并不是唯一的，其关键在与每次找到权值最小的两个结点，我是用了 stl 中的优先队列的方式。
2.  Huffman 编码的过程比较简单，对整棵树进行一次完整的遍历既可
3.  平均长度需要 第 2 步得到的编码，与给定数据中的频率结合而得出

**概要设计：**

- 实现函数 1 :根据给定数据，进行 Huffman 建树

  > 函数名称：void HuffmanTree<T>::CreateBYWordsAndValue() <br>
  > 功能描述: 根据给定数据，进行 Huffman 建树 <br>
  > 参数列表: void（程序中需要输入单词的数据） <br>
  > 返回结果：void

- 实现函数 2 :求各个单词的加权和

  > 函数名称：double void HuffmanTree<T>::Lenall(HuffmanTreeNode<T> \*tmp) <br>
  > 功能描述: 求各个单词的加权和 <br>
  > 参数列表: huffman 树的 root 结点指针 <br>
  > 返回结果： 单词的加权和

- 实现函数 3 :进行 Huffman 编码

  > 函数名称：void HuffmanTree<T>::encode(HuffmanTreeNode<T> \*tmp, std::string s) <br>
  > 功能描述: 进行 Huffman 编码 <br>
  > 参数列表: huffman 树的 root 结点指针，空字符串 s <br>
  > 返回结果：void

**详细设计：**

```cpp
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
        int tot = ptr1->value;
        tot += ptr2->value;
        HuffmanTreeNode<T> *tmp = new HuffmanTreeNode<T>(tot);
        tmp->lchild = ptr1;
        tmp->rchild = ptr2;

        P.push(tmp);
    }
    this->root = P.top();
}
template<class T>
double void HuffmanTree<T>::Lenall(HuffmanTreeNode<T> *tmp)
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
template <class T>
void HuffmanTree<T>::encode(HuffmanTreeNode<T> *tmp, std::string s)
{
    if (tmp == nullptr)
    {
        return;
    }
    if (tmp->flag)
    {
        res[tmp->pos] = s;
        return;
    }
    encode(tmp->lchild, s + '0');
    encode(tmp->rchild, s + '1');
}
```

**调试分析：**

**Input:**
15
The 1192
of 677
a 541
to 518
and 462
In 450
that 242
he 195
is 190
at 181
on 174
for 157
his 138
are 124
be 123

**Output:**
In 1101
The 01
a 001
and 1110
are 111111
at 10011
be 111110
for 10001
he 11001
his 10000
is 11000
of 101
on 10010
that 11110
to 000
average find number: 3.562081

**结论与展望：**

结论：

huffman 又称最优编码，它是一种变长编码。它有着出现频率越高，编码越短的规律。所以使加权平均和最小，所以广泛应用于数据压缩中。

展望:

1.  在大一的时候，某学期的大作业我的选题就是 Huffman 编码在压缩技术中的应用，当时在借助别人的一部分代码（比特流的部分）完成了压缩程序和特定的解压缩程序，并可实际产生压缩效果。
2.  Huffman 编码还是有可以优化的地方的，比如针对解码时间过长等

---

## 第六题：最短路算法

**问题概述:**

针对一个有若干点和边的图 G，给定两个点，求出其最短路径并记录，这便是最短路问题的
基本问题。这里主要介绍 dijkstra 算法。

**需求分析:**

1.  dijkstra 算法本质是贪心，每次选取的点都是距离不可能在被缩小的。其最终得到的结果是给定点到其他点的最短路
2.  这个算法只能计算单元最短路，而且不能计算负权值。
3.  最短路径的记录的本质是记录前驱，即被谁更新
4.  正确理解最短路上的也是最短路对理解最短路径的记录很重要

**概要设计：**

- 实现函数 1 :根据图 G，求出某点 sec 到其他点的最短距离

  > 函数名称：void dijkstra(int sec, int n) <br>
  > 功能描述: 根据给定数据，进行 Huffman 建树 <br>
  > 参数列表: 图 G，出发点 sec <br>
  > 返回结果：void(sec 到其他节点保存在全局数组中)

- 实现函数 2 :求各个单词的加权和

  > 函数名称：void print(int sec, int n) <br>
  > 功能描述: 打印 sec 到个点最短距离的路径 <br>
  > 参数列表: 图 G，出发点 sec <br>
  > 返回结果： void(sec 到其他节点保存在全局数组中)

- 算法复杂度分析：

  > 总复杂度 O{N\*N} >初始化 dis 数组 O(N) >进行 N-1 次选点，每次需要遍历整个数组，找到最小值，并且尝试对每个点进行松弛则有 O（（N-1）\*N）

- 部分算法实现思路：

  > 1.  先取一点 v[0]作为起始点，初始化 dis[i],d[i]的值为 v[0]到其余点 v[i]的距离 w[0][i]，如果直接相邻初始化为权值，否则初始化为无限大；

  > 2.  将 v[0]标记，vis[0] = 1(vis 一开始初始化为 0)；

  > 3.  找寻与 v[0]相邻的最近点 v[k]，将 v[k]点记录下来，v[k]与 v[0]的距离记为 min；

  > 4.  把 v[k]标记，vis[k]=1；

  > 5.  查询并比较，让 dis[j]与 min+w[k][j]进行比较，判断是直接 v[0]连接 v[j]短，还是经过 v[k]连接 v[j]更短，即 dis[j]=MIN(dis[j],min+w[k][j])；

  > 6.  继续重复步骤 3 与步骤 5，知道找出所有点为止。

**详细设计：**

```cpp
const int maxn = 1e3;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn], dis[maxn], path[maxn]; //path数组用于记录路径

void dijkstra(int sec, int n)
{
    int min, min_i;
    int vis[maxn] = {0};
    for (int i = 0; i < n; i++)
    {
        dis[i] = mp[sec][i];
    }
    vis[sec] = 1;
    dis[sec] = 0;
    for (int i = 1; i < n; i++)
    {
        min = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                min_i = j;
            }
        }
        vis[min_i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (dis[j] > min + mp[min_i][j])
            {
                path[j] = min_i;
                dis[j] = min + mp[min_i][j];
            }
        }
    }
}
void print(int sec, int n)
{
    stack<int> q;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (path[j] != -1)
        {
            q.push(j);
            j = path[j];
        }
        q.push(j);
        cout << sec << "->" << i << ",length==" << dis[i] << ",path: " << sec;
        while (!q.empty())
        {
            cout << "  " << q.top();
            q.pop();
        }
        printf("\n");
    }
}
```

**调试分析：**

**Input:**

5 7
0 1 10
0 2 18
2 1 5
1 3 5
3 2 2
3 4 2
4 2 2

**Output:**

0->1,length\=\=10,path: 0 1
0->2,length\=\=17,path: 0 1 3 2
0->3,length\=\=15,path: 0 1 3
0->4,length\=\=17,path: 0 1 3 4

**结论与展望：**

结论：

Dijkstra 算法是典型的单源最短路径算法，用于计算一个节点到其他所有节点的最短路径。主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。注意该算法要求图中不存在负权边。

展望：

1.  使用堆或者优先队列来寻找最小的值，来代替遍历所有。每次新加入点时，只尝试松弛与他相连的点。这两步可以将 Dijkstra 的时间复杂度降低到 O（NLogN）
2.  Dijkstra 算法的好处时简单，能处理大多数问题，但不能处理负权的情况，所以还有别的最短路算法。比较常用的有 floyd ，bellman，spfa 算法。

---

## 第七题：最小生成树算法

**问题概述:**
一个有 n 个结点的连通图的生成树是原图的极小连通子图，且包含原图中的所有 n 个结点，并且有保持图连通的最少的边。最小生成树可以用 kruskal 算法或 prim 算法求出。
**需求分析:**

1.  最小生成树有两种不同的算法，kruskal 算法或 prim 算法，他们的时间复杂度不同，适用于分别更加适合稀疏图与稠密图。
2.  Prim 算法的本质和 Dijkstra 相同都是贪心，在整体思路上非常相似。每次迭代选择代价最小的边对应的点，加入到最小生成树中。算法从某一个顶点 s 开始，逐渐长大覆盖整个连通网的所有顶点。
3.  kruskal 算法是每迭代一次就选择一条满足条件的最小代价边，加入到最小生成树的边集合里，直到形成最小生成树。
4.  kruskal 算法要用简易的并查集来确定两个子图是否是联通的。
5.  并查集需要使用路径压缩来节约时间，不然会是巨大的时间开销

**概要设计：**

- 实现函数 1 :prim 算法

  > 函数名称：int prim() <br>
  > 功能描述: prim 算法 <br>
  > 参数列表: 图 G，出发点 sec（全局） <br>
  > 返回结果：最小生成树结果

- 实现函数 2 :kruskal 算法

  > 函数名称：int slove() <br>
  > 功能描述: kruskal 算法 <br>
  > 参数列表: 图 G，出发点 sec，并查集数组（全局） <br>
  > 返回结果： 最小生成树结果

- 实现函数 3 :查询一个节点属于哪个子图

  > 函数名称：int find(int i) <br>
  > 功能描述: 查询一个节点属于哪个子图 <br>
  > 参数列表: 点 i <br>
  > 返回结果： 属于的子图

- 实现函数 4 :判断现在有几个子图

  > 函数名称：int CheckSector() <br>
  > 功能描述: 判断现在有几个子图 <br>
  > 参数列表: void <br>
  > 返回结果： 子图的数量

- 算法复杂度分析：

  > Prim 算法 总时间复杂度 O(N\*N),堆优化 O(N\*NLogN) <br>

  > kruskal 算法 总时间复杂度 O(M\*LogV) <br>
  > 总复杂度表示为：O(V) + O(E log E) + O(E log V)； <br>
  > 当图为稠密图时，时间复杂度可表示为 O(E log E)； <br>
  > 一般图基本为稀疏图|E| < |V|^2，时间复杂度可表示为 O(E log V)。

- 部分算法实现思路：
  Prim:

  > (1)将图 G 看做一个森林，每个顶点为一棵独立的树 <br>
  > (2)将所有的点加入点的集合 S，即一开始 S = G <br>
  > (3)选择一个点 Q 离开 S，加入一个空点集 R，然后定义一个点到一个集合里最短距离为这个点到点集内所有点的最短距离 <br>
  > (4)不断从 S 中选择点离开 S 加入 Q，选取原则为离 Q 最近的一个点，直到所有点加入 Q，每次加入点所连接的最短路集合就是最小生成树 <br>

Kruskal:

> (1)将图 G 看做一个森林，每个顶点为一棵独立的树 <br>
> (2)将所有的边加入集合 S，即一开始 S = E
> (3)从 S 中拿出一条最短的边(u,v)，如果(u,v)不在同一棵树内，则连接 u,v 合并这两棵树，同时将(u,v)加入生成树的边集 E' <br>
> (4)重复(3)直到所有点属于同一棵树，边集 E'就是一棵最小生成树

**详细设计：**

```cpp
const int MAXN = 10010;
int n, m;
struct edge
{
    int v, u, w;
    edge(int v, int u, int w) : v(v), u(u), w(w) {}
    bool operator<(const edge f) const
    {
        if (w < f.w)
            return true;
        return false;
    }
};
vector<edge> edges;
int r[MAXN];
int find(int i)
{
    return r[i] == i ? i : r[i] = find(r[i]);
}
int CheckSector()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] == i)
            cnt++;
    }
    return cnt;
}
int slove()
{
    int sum = 0;
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= m; i++)
    {
        int x = find(edges[i].v), y = find(edges[i].u);
        if (x != y)
        {
            sum += edges[i].w;
            r[y] = x;
        }
    }
    if (CheckSector() == 1)
        return sum;
    return -1;
}
```

```cpp
int ad[2000][2000];
const int maxn = 999999999;
int n;
int prim()
{
    int sum = 0, min_id;
    int shortest[n + 1];
    for (int i = 1; i <= n; i++)
        shortest[i] = ad[1][i];
    for (int i = 1; i < n; i++)
    {
        int minx = maxn;
        min_id = -1;
        for (int j = 1; j <= n; j++)
        {
            if (shortest[j] < minx && shortest[j] != 0)
            {
                minx = shortest[j];
                min_id = j;
            }
        }
        if (min_id != -1)
        {
            sum += minx;
            shortest[min_id] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (ad[min_id][j] < shortest[j])
                    shortest[j] = ad[min_id][j];
            }
        }
        else
            return -1;
    }
    return sum;
}
```

**调试分析：**

**Input:**

3 3
1 2 1
1 3 2
2 3 4

**Output:**

3

**Input2:**

10 6
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 5 6
3 6 4
4 3 5
4 6 2
5 6 6

**Output2:**

15

**结论与展望：**

结论：

kruskal 算法与 prim 算法均可以解决最小生成树，不过根据 krusal 与 prim 的时间复杂度分析可知，prim 更适合稠密图，kruskal 更适合稀疏图。不过 krusal 写起来更加简单。

展望：

1.  prim 算法和最短路的 Dijstra 算法非常相似，有着相同的算法思想。同样也可以对其进行相同的优化，即通过优先队列或者堆，来快速寻找最小值，可以将 prim 算法优化到 O(N\*NLogN)
2.  Kruskal 算法的主要优化的地方就是在使用并查集的路径压缩，是一项常规优化

---

## 第八题：快速排序算法及其改进

**问题概述:**

快速排序是对冒泡排序的一种改进。利用了二分的思想，其思想为，选取基准点，使比其小的到他的一边，比他大的到另一边。
然后对区间进行递归，最终完成排序。

**需求分析:**

1.  快速排序整个分为两个部分，第一部分为一趟快排，第二部分为递归二分区间
2.  第一部分，方法为选取区间第一个点为基准点，从区间左端向右找，找到比基准点大的值，再从区间右端向左找，找到比基准点小的，交换这两个值，反复该步骤直到左右相遇，然后将基准点交换到相遇的地方。

**概要设计：**

- 实现函数 1 :QuickSort

  > 函数名称：void QuickSort(int r[], int bot, int top) <br>
  > 功能描述: 对给定数组与范围完成快速排序 <br>
  > 参数列表: 数组 r,左端点，右端点 <br>
  > 返回结果：void

- 实现函数 2 :OnceQuickSort,快排的一趟

  > 函数名称：int OnceQuickSort(int r[], int bot, int top) <br>
  > 功能描述: 对给定数组与范围进行一趟快排 <br>
  > 参数列表: 数组 r,左端点，右端点 <br>
  > 返回结果： 基准点坐标

- 时间复杂度分析

  > 在最差情况下，划分由 n 个元素构成的数组需要进行 n 次比较和 n 次移动。因此划分所需时间为 O(n) 。最差情况下，每次主元会将数组划分为一个大的子数组和一个空数组。这个大的子数组的规模是在上次划分的子数组的规模减 1 。该算法需要 (n-1)+(n-2)+…+2+1= O(n^2) 时间。 <br>

  > 在最佳情况下，每次主元将数组划分为规模大致相等的两部分。设 T(n) 表示使用快速排序算法对包含 n 个元素的数组排序所需的时间，因此，和归并排序的分析相似，快速排序的 T(n)= O(nlogn)。 <br>

**详细设计：**

```cpp
void QuickSort(int r[], int bot, int top)
{
    if (bot < top)
    {
        int pivot = OnceQuickSort(r, bot, top);
        QuickSort(r, bot, pivot - 1);
        QuickSort(r, pivot + 1, top);
    }
}
int OnceQuickSort(int r[], int bot, int top)
{
    r[0] = r[bot];
    movenum++;
    while (bot < top)
    {
        while (r[top] >= r[0] && top > bot)
        {
            cmpnum++;
            top--;
        }
        swap(r[top], r[bot]);
        movenum += 3;
        while (r[bot] <= r[0] && top > bot)
        {
            bot++;
            cmpnum++;
        }
        swap(r[bot], r[top]);
        movenum += 3;
    }
    return bot;
}
```

**调试分析：**
|Input|Output|cmp num|move num|
|:----|:-----|:-----|:-----|
|477 677 194 652 90 970 304 169 67 834|67 90 169 194 304 477 652 677 834 970|23|73|
|731 84 343 814 427 343 700 218 19 805|19 84 218 343 343 427 700 731 805 814|27|48|

**结论与展望：**

结论：快速排序是一种非稳定的排序，平均速度是非常快的，但再最坏情况下会退化为冒泡排序。

展望：

1.  快速排序的基准点选取是有多种方法的，固定点（第一个/最后一个），随机选取等
2.  快速排序还可以加上一些优化,比如划分的区间比较小时，可以改为插入排序。

## 总结

数据结构课程在我看来时计算机专业最重要的课程之一。我在摘要中也提到了，对于我校开设有些迟的遗憾。不过总算是系统地对数据结构进行了学习。本学期在数据结构课程上收获还是颇丰的，最大的收益应该是从更系统的角度去来面对数据结构。过去可能是对很多数据结构知而零散。现在站在更高的角度，从存储结构的选用，复杂度，从数据的关系（一对一等），如何优化等有了更多立体的思考。

比较遗憾的是两件事，一件事这门课的时间比较短，有些篇目并没有涉及到，只能等到之后自己再去学习。第二件事是有因为其他科目考试等影响因素，中间一些课堂比较懈怠，等到了要提交代码的时候，没有来得及对代码做最最后的整理与完善。

数据结构的学习并不会随着这一个学期的结束而结束，在日后的学习中会反复的回到这里。
