#include <iostream>
#include <cstring>
#include <cmath>
#include "include/get_logs.hpp"
#include "include/CreateMenu.hpp"
#include "include/structure.hpp"

using namespace std;

void get_ip(int *i, char buf[], char logs_ip[])
{
    while(buf[*i] != '-') {
            logs_ip[*i] = buf[*i];
            (*i) ++;
        }
    for(int j = 0; j < strlen(logs_ip); j ++){
        if(logs_ip[j] == ' ')logs_ip[*i] = '\0';
    }
}
void get_time(int *i, char buf[], char logs_time[])
{
    while(buf[*i] != '[')(*i) ++;
    (*i) ++;
    int j = 0;
    while(buf[(*i) - 1] != ' '){
        logs_time[j ++] = buf[*i];
        (*i) ++;
    }
}
void get_req(int *i, char buf[], char logs_req[])
{
    int j = 0;
    int flag = 1; //由于英文"都一样，故增加一个判断标志
    while(buf[*i] != '\"')(*i) ++;
    while(flag){
        if(buf[(*i)] == '\"' && j != 0)flag = 0; 
        logs_req[j ++] = buf[*i];
        (*i) ++;
    }
}
void get_path(int *i, char buf[], char logs_path[])
{
    int j = 0;
    int flag = 1; //由于英文"都一样，故增加一个判断标志
    while(buf[*i] != '\"')(*i) ++;
    while(flag){
        if(buf[(*i)] == '\"' && j != 0)flag = 0; 
        logs_path[j ++] = buf[*i];
        (*i) ++;
    }
}
void get_web_ser(int *i, char buf[], char logs_web[])
{
    int j = 0;
    int flag = 1; //由于英文"都一样，故增加一个判断标志
    while(buf[*i] != '\"')(*i) ++;
    while(flag){
        if(buf[(*i)] == '\"' && j != 0)flag = 0; 
        logs_web[j ++] = buf[*i];
        (*i) ++;
    }
}

void get_time_detail(char logs_time[], Ltime* t)
{
    for(int i = 0; i < 2; i ++)(*t).day += (logs_time[i]-'0') * int(pow(10, 1 - i));
    for(int i = 3, j = 0; i < 6; i ++)(*t).month[j ++] = logs_time[i];
    for(int i = 7; i < 11; i ++)(*t).year += (logs_time[i]-'0')* int(pow(10, 10 - i));
    for(int i = 12; i < 14; i ++)(*t).h += (logs_time[i]-'0')*int(pow(10,13-i));
}

