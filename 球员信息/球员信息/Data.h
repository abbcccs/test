#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//system("cls");����
#include <string.h> 
#include<ctype.h>  //�����ַ������ָ��

typedef struct play
{
	int num;			//���
	char name[20];		//����
	char gender[10];	// �Ա�
	int  age;			// ����
	char height[20];	//���
	float wages;        //����
	char  addr[20];     //סַ
	char Tel[15];		//�绰
}PLAY;

typedef PLAY DataType;
typedef struct Data
{
	DataType* a;
	int size;
	int capcity;
}Data;

//���ܺ�������
int login();	//��¼

void view(Data* pd);	//��ʾ��Ա��Ϣ
void add(Data* pd);		//����
void revise(Data* pd);	//�޸�
void del(Data* pd);		//ɾ��
void sort(Data* pd);	//����
void inquire(Data* pd);	//��ѯ
void inquire_num(Data* pd);//����Ų�ѯ
void inquire_name(Data* pd);//��������ѯ
void save(Data* pd);	//����
void statistics(Data* pd);	//����ͳ��
void read(Data* pd);		//��ȡ����
void DataInit(Data* pd);