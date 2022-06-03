#include <iostream>
#include <cstring>
#include "IPLocator.hpp"
using namespace std;

#define ll long long

ll transIP(char ip[]); //将字符型ip转码为整数型

int IPhash(char ip[], int st[]);      //利用hash函数将IP离散到[1~10000]内

void TransToIP(int a);  //将整数型转码为IP