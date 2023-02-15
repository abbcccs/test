#define _CRT_SECURE_NO_WARNINGS 1

#include"Data.h"


//菜单
void menu()
{
	printf("		  欢迎进入《球员信息管理系统》  \n");
	printf("******************************************************************\n");
	printf("**	1.显示球员信息		**	2.添加球员信息		**\n");
	printf("**	3.修改球员信息		**	4.删除球员信息		**\n");
	printf("**	5.查找球员信息		**	6.对球员排序		**\n");
	printf("**	7.统计球员信息		**	0.退出系统		**\n");
	printf("******************************************************************\n");
}
int main()
{
	int num;
	Data d;
	DataInit(&d);
	read(&d);
	do
	{
		menu();
		printf("请选择菜单编号:");
		scanf("%d", &num);
		system("cls");     //清屏
		switch (num)
		{
		case 1: view(&d);
			break;
			case 2: add(&d);
				break;
			case 3: revise(&d);
				break;
			case 4: del(&d);
				break;
			case 5: inquire(&d);
				break;
			case 6: sort(&d);
				break;
			case 7:statistics(&d);
				break;
		case 0: save(&d);
			printf("退出系统\n");
			exit(0);
			break;
		default:printf("请选择菜单项：");
		}
		printf("\n");
		system("cls");
	} while (num);
	//if (login() == 1)
	//{
	//	printf("登陆成功\n");
	//	system("pause");   //暂停
	//	system("cls");     //清屏
	//	
	//}
	return 0;
}


