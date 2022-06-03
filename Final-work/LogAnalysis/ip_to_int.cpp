#include <iostream>
#include <stack>
#include <cstring>
#include "include/IPint.hpp"
using namespace std;


int IPhash(char ip[], int st[]){
    int ip_num[5];
    int t = 0;
    int sum = 0;
    for(int i = 0, j = 0; i < strlen(ip); i ++){
        if(ip[i] != '.'){
            t = t * 10 + (ip[i] - '0');
        }
        else {
            sum += t * (i + 1);
            ip_num[j ++] = t;
            t = 0;
        }
    }
    return sum;
}

ll transIP(char ip[]){
    int ip_num[5];
    int t = 0;
    for(int i = 0, j = 0; i < strlen(ip); i ++){
        if(ip[i] != '.'){
            t = t * 10 + (ip[i] - '0');
        }
        else {
            ip_num[j ++] = t;
            t = 0;
        }
    }
    return ((ip_num[0]<<24)|(ip_num[1]<<16)|(ip_num[2]<<8)|ip_num[3]);
}

void TransToIP(int a){
    cout<<((a&0xff000000)>>24)<<"."<<((a & 0x00ff0000)>>16)<<"."<<((a&0x0000ff00)>>8)<<"."<<(a & 0x000000ff)<<endl;
}