#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//system("cls");清屏
#include <string.h> 
#include<ctype.h>  //用于字符处理的指令

typedef struct play
{
	int num;			//编号
	char name[20];		//姓名
	char gender[10];	// 性别
	int  age;			// 年龄
	char height[20];	//身高
	float wages;        //工资
	char  addr[20];     //住址
	char Tel[15];		//电话
}PLAY;

typedef PLAY DataType;
typedef struct Data
{
	DataType* a;
	int size;
	int capcity;
}Data;

//功能函数声明
int login();	//登录

void view(Data* pd);	//显示球员信息
void add(Data* pd);		//增加
void revise(Data* pd);	//修改
void del(Data* pd);		//删除
void sort(Data* pd);	//排序
void inquire(Data* pd);	//查询
void inquire_num(Data* pd);//按编号查询
void inquire_name(Data* pd);//按姓名查询
void save(Data* pd);	//保存
void statistics(Data* pd);	//数据统计
void read(Data* pd);		//获取数据
void DataInit(Data* pd);