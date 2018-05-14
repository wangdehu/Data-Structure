//列车时刻表管理系统
//案例描述：一个火车要对进出本站的列车信息进行计算机管理，包括建立、增加、删除、查询、修改车次信息等。
// 列车信息有车次、开点、到点、始发站、终点站等。
//已知进出该站的列车车次变化较多。

#include <iostream>
#include <list>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Node
{
    string name;
    vector<list<Node *> *> con;
    Node(string name) : name(name) {}
};
typedef list<Node *> Edge;
int cnt = 0;

vector<Node> nodes;
vector<Edge *> E;
void citys_output()
{
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        cout << "#" << i + 1 << nodes[i].name << endl;
    }
}
void road_output(Edge *p)
{
    for (auto i : (*p))
    {
        cout << i->name << " ";
    }
    cout << endl;
}
void roads_output()
{
    int len = E.size();
    for (int i = 0; i < len; ++i)
    {
        cout << "#" << i + 1 << " : " << flush;
        road_output(E[i]);
    }
}

void add_road()
{
    int len = E.size();
    cout << "please input city id until input -1" << endl;
    citys_output();
    int city_id = -1;
    Edge *p = new Edge;
    E.push_back(p);
    while (1)
    {
        cin >> city_id;
        if (city_id == -1)
            break;
        p->push_back(&nodes[city_id - 1]);
        nodes[city_id - 1].con.push_back(p);
    }
}
void add_city()
{
    cout << "please input city name" << endl;
    string name;
    cin >> name;
    nodes.push_back(Node(name));
}
void get_road_by_city()
{
    cout << "please input city id" << endl;
    citys_output();
    int city_id;
    cin >> city_id;
    int rlen = nodes[city_id - 1].con.size();
    if (!rlen)
    {
        cout << "没有经过该城市的线路！" << endl;
        return;
    }
    for (auto i : nodes[city_id - 1].con)
    {
        road_output(i);
    }
}
void output()
{
    cout << endl
         << "--------------------------------------------------" << endl;
}
void road_remove()
{
    cout << "please input road id" << endl;
    roads_output();
    int road_id;
    cin >> road_id;
    for (auto i : *E[road_id - 1])
    {
        i->con.erase(remove(i->con.begin(), i->con.end(), E[road_id - 1]),
                     i->con.end());
    }
    delete E[road_id - 1];
    E.erase(E.begin() + road_id - 1, E.begin() + road_id);
}
int main()
{
    add_city();
    output();
    add_city();
    output();
    add_city();
    output();
    add_city();
    output();
    add_city();
    output();

    add_road();
    output();
    add_road();
    output();

    get_road_by_city();
    output();
    get_road_by_city();
    output();
    get_road_by_city();
    output();

    roads_output();
    output();
    road_remove();
    output();
    roads_output();
    output();

    get_road_by_city();
    output();

    return 0;
}