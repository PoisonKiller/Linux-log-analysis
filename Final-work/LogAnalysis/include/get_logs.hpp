#ifndef _GET_LOGS_
#define _GET_LOGS__

#include <iostream>
#include <cstring>
#include "CreateMenu.hpp"
#include "structure.hpp"
using namespace std;

//获取ip
void get_ip(int *i, char buf[],char logs_ip[]);
//获取时间
void get_time(int *i, char buf[], char logs_time[]);
//获取请求类型
void get_req(int *i, char buf[], char logs_time[]);
//获取网站路径
void get_path(int *i, char buf[], char logs_time[]);
//获取代理服务器类型
void get_web_ser(int *i, char buf[], char logs_time[]);
//处理时间
void get_time_detail(char logs_time[], Ltime* t);


#endif