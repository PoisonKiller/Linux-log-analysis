#ifndef _GET_LOGS_
#define _GET_LOGS__

#include <iostream>
#include <cstring>
#include "CreateMenu.hpp"
#include "structure.hpp"
using namespace std;

//��ȡip
void get_ip(int *i, char buf[],char logs_ip[]);
//��ȡʱ��
void get_time(int *i, char buf[], char logs_time[]);
//��ȡ��������
void get_req(int *i, char buf[], char logs_time[]);
//��ȡ��վ·��
void get_path(int *i, char buf[], char logs_time[]);
//��ȡ�������������
void get_web_ser(int *i, char buf[], char logs_time[]);
//����ʱ��
void get_time_detail(char logs_time[], Ltime* t);


#endif