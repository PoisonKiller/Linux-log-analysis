#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/get_logs.hpp"
#include "include/CreateMenu.hpp"
#include "include/IPLocator.hpp"
#include "include/IPint.hpp"
#include "include/structure.hpp"

using namespace std;

#define ll long long
int st[10000];

LOG log[1005];

ifstream fin;
ofstream fout;

int main()
{
    fin.open("./1000test.log");
    if(!fin.is_open())
    {
        std::cerr<<"cannot open the file";
    }
    if(!fin)
    {
        std::cerr<<"cannot open the file";
    }  
    char buf[1021]={0};
    int cnt = 0;
    while(fin.getline(buf,sizeof(buf)))
    {
        int i = 0;
        get_ip(&i, buf, log[cnt].ip);
        get_time(&i, buf, log[cnt].time);
        get_req(&i, buf, log[cnt].req);
        get_path(&i, buf, log[cnt].path);
        get_web_ser(&i, buf, log[cnt].web_ser);
        log[cnt].intIP = IPhash(log[cnt].ip, st);
        get_time_detail(log[cnt].time, &(log[cnt].detail_time));
        cnt ++;
    } 

    show_menu();
    get_order(log, cnt, st);

}
