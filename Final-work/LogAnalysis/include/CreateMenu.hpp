#ifndef CREA_MENU
#define CREA_MENU

#include <iostream>
#include <cstring>
#include <algorithm>
#include "IPLocator.hpp"
#include "structure.hpp"
using namespace std;

//ip内的时间结构
typedef struct Time
{
    int day = 0;
    char month[5];
    int year = 0;
    int h = 0;
    int min = 0;
}Ltime;

//日志数据结构
typedef struct logs{
    char ip[100];
    char time[50];
    char req[50];
    char path[50];
    char web_ser[100];
    char intIP;
    Ltime detail_time; 
}LOG;

void show_menu();
void get_order(LOG log[], int cnt, int st[]);
void show_all_logs(LOG log[], int cnt);
void show_log(LOG log[], int index);
void show_ip_by_time(LOG log[], int cnt);
void show_IPdetail(LOG log[], int cnt);
void show_action(LOG log[],int index, int cnt);
void show_num(int cnt);
//时间上的用户访问分布
void user(LOG log[], int cnt);

#endif