// 5.	病人看病模拟程序
// 编写一个程序，反映病人到医院看病，排队看医生的情况。在病人排队过程中，主要重复两件事：
// （1）	病人到达诊室，将病历本交给护士，排到等待队列中候诊
// （2）	护士从等待队列中取出下一位病人的病历，该病人进入诊室就诊
// 要求模拟病人等待就诊这一过程。程序采用菜单方式，其选项及功能说明如下：
// 	    排队――输入排队病人的病历号，加入病人排队队列中；
//  	就诊――病人排队队列中最前面的病人就诊，并将其从队列中删除；
// 	    查看排队――从对首到队尾列出所有的排队病人的病历号；
// 	    不再排队，余下依次就诊――从对首到队尾列出所有的排队病人的病历号，并退出运行；
//  	下班――退出运行。
#include <bits/stdc++.h>
using namespace std;
int menu()
{
    cout << "please input fuction!" << endl;
    cout << "1.add queue!" << endl;
    cout << "2.pop queue!" << endl;
    cout << "3.output!" << endl;
    cout << "4.pop all,quit" << endl;
    cout << "5.quit" << endl;
    int value;
    cin >> value;
    return value;
}
int main()
{
    int tmp;
    queue<int> q;
    queue<int> q2;

    int choice;
    while (1)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "please input id" << endl;
            cin >> tmp;
            q.push(tmp);
            cout << tmp << " be add queue!" << endl;
            break;
        case 2:
            tmp = q.front();
            cout << "tmp be pop!" << endl;
            q.pop();
            break;
        case 3:
            q2 = q;
            cout << "there are all person id :" << endl;
            while (!q2.empty())
            {
                tmp = q2.front();
                cout << tmp << " ";
                q2.pop();
            }
            cout << endl;
            break;
        case 4:
            while (!q.empty())
            {
                tmp = q.front();
                cout << "tmp be pop!" << endl;
                q.pop();
            }
        case 5:
            cout << "quit!!!" << endl;
            return 0;
            break;
        }
    }
}