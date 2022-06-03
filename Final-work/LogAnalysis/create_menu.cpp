#include <iostream>
#include <cstring>
#include "include/CreateMenu.hpp"
#include "include/IPLocator.hpp"
#include "include/IPint.hpp"
#include "include/structure.hpp"

using namespace std;

void show_menu()
{
    printf("--------------menu------------\n");
    printf("---You can input as follows:---\n");
    printf("[1] ---------show all of the logs\n");
    printf("[2] ---------show the detail of the los you want to get\n");
    printf("[3] ---------show the ip ordered by time\n"); 
    printf("[4] ---------show the ip's information\n");
    printf("[5] ---------output all of the action of the ip you input\n");
    printf("[6] ---------get the number of the logs\n");
    printf("[7] ---------show the menu again\n");
    printf("[0] ---------exit this project!\n");
    printf("--------------------------------------------------\n");
}

//获取指令
void get_order(LOG log[], int cnt, int st[]){
    int order;
    scanf("%d", &order);
    int index;
    while(order != 0){
        switch (order)
        {
        case 1:
            show_all_logs(log, cnt);
        case 2:
            printf("input the index of the log you want to get: ");
            scanf("%d", &index);
            show_log(log, index);
            break;
        case 3:
            show_ip_by_time(log, cnt);
            break;
        case 4:
            user(log, cnt);
            break;
        case 5:
            printf("input the index of the ip's actions you want to get: ");
            scanf("%d", &index);
            show_action(log, index, cnt);
            break;
        case 6:
            show_num(cnt);
            break;
        case 7:
            show_menu();
            break;
        default:
            printf("input ERROR, and input again: ");
            break;
        }
        scanf("%d", &order);
    }
    printf("exit successfully!\n");
    
}

//按下1时
void show_all_logs(LOG log[], int cnt)
{
    for(int i = 0; i < cnt; i ++){
        printf("--------the %dth log-------\n", i + 1);
        show_log(log, i);
    }
    printf("press 7 can return back menu and press 0 can exit!\n");
}

//按下2时
void show_log(LOG log[], int index)
{
    std::cout<<log[index].ip<<std::endl;
    std::cout<<log[index].time<<std::endl;
    std::cout<<log[index].req<<std::endl;
    std::cout<<log[index].path<<std::endl;
    std::cout<<log[index].web_ser<<std::endl;
    printf("press 7 can return back menu and press 0 can exit!\n");
}

//按下4时
void user(LOG log[], int cnt)
{
    printf("------------day's distribution---------\n");
    int st = 0;
    int d; //day and h

    int num = 0;
    d = log[0].detail_time.day;
    for(int i = 0; i < cnt; i ++){
        int temp = int(log[i].detail_time.day);
        if(temp == d || d > 1000){
            num ++;
        }
        else{
            for(int j = 0; j < 11; j ++)cout << log[i].time[j];
            printf("\tnum: %d\n",num);
            num = 1;
            d = temp;
        }
    }
    for(int j = 0; j < 11; j ++)cout << log[cnt - 1].time[j];
    printf("\tnum: %d\n",num);

    printf("------------h's distribution---------\n");
    d = log[0].detail_time.h;
    num = 1;
    int temp;
    // for(int i = 0; i < cnt; i ++){
    //     temp = log[i].detail_time.h;
    //     if(temp == d || d > 25)num ++;
    //     else{
    //         for(int j = 0; j < 11; j ++)cout << log[i].time[j];
    //         cout <<"\t" << d << ":00~" << d+1<< ":00\tnum: "<< num << endl;;
    //         num = 1;
    //         d = temp;
    //     }
    // }
    int sum = cnt;
    for(int i = 0; i < 24; i ++){
        num = 0;
        for(int j = 0; j < cnt; j ++){
            temp = int(log[j].detail_time.h);
            if(temp == i)num ++;
        }
        sum -= num;
        if(i == 23)num = sum;
        cout << i << ":00~" << i+1<< ":00\tnum: "<< num << endl;
    }
    printf("press 7 can return back menu and press 0 can exit!\n");
}

//按下3时
void show_ip_by_time(LOG log[], int cnt){
    //IPLocator ipl("wry utf-8.dat");
    for(int i = 0; i < cnt; i ++){
        std::cout<<log[i].time<<"\t\t";
        std::cout<<log[i].ip<<std::endl;
    }
    printf("press 7 can return back menu and press 0 can exit!\n");
}

void show_action(LOG log[],int index, int cnt){
    int u = log[index].intIP;
    cout << "Ip:\t" << log[index].ip << endl;
    int n = 1;
    for(int j = 0; j < cnt; j ++){
        if(log[j].intIP == u){
            printf("%dth\t", n ++);
            cout << log[j].req ;
            for(int i = strlen(log[j].req); i < 30; i ++) cout << ' ';
            cout << log[j].time << endl;
        }
    }
    printf("press 7 can return back menu and press 0 can exit!\n");
}

void show_num(int num){
    printf("There are %d logs int the file\n", num);
    printf("press 7 can return back menu and press 0 can exit!\n");
}