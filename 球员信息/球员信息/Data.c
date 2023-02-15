#define _CRT_SECURE_NO_WARNINGS 1

#include"Data.h"


void DataInit(Data* pd)
{
	pd->a = (DataType*)malloc(sizeof(DataType) * 4);
	if (!pd->a)
	{
		perror("malloc fail");
		exit(-1);
	}
	pd->capcity = 4;
	pd->size = 0;
}
// 登录（共三次机会，登录失败后会自动退出）
//int login()
//{
//	long passworld;
//	printf("欢迎登录《球员信息管理系统》\n");
//	printf("--------【登录账号】--------\n");
//	int a = 0;
//	printf("请输入密码:");
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%ld", &passworld);
//		if (passworld == 123456)
//		{
//			a = 1;
//			return a;
//		}
//		else if (i == 2)
//		{
//			printf("登录次数已用完，登陆失败!!");
//		}
//		else
//		{
//			printf("密码错误，还有%d次机会，请重新输入！\n", 2 - i);
//		}
//
//	}
//	return a;
//}



//保存
void save(Data* pd)
{
	FILE* fo = fopen("data.txt", "wb");
	if (!fo)
	{
		perror("fopen fail");
		exit(-1);
	}
	for (int i = 0; i < pd->size; i++)
	{
		fwrite(&(pd->a[i]), sizeof(PLAY), 1, fo);
	}
}


void isfull(Data* pd)
{
	if (pd->size == pd->capcity)
	{
		int newcapcity = pd->capcity * 2;
		DataType* tmp = (DataType*)realloc(pd->a, sizeof(DataType) * newcapcity);
		if (!tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		pd->a = tmp;
		pd->capcity = newcapcity;
	}
}
//导入
void read(Data* pd)
{
	FILE* fin = fopen("data.txt", "rb");
	if (!fin)
	{
		perror("fopen fail");
		exit(-1);
	}
	int i = 0;
	while (fread(&(pd->a[i]), sizeof(PLAY), 1, fin) != 0)
	{
		i++;
		pd->size++;
		isfull(pd);
	}
	fclose(fin);
}

//浏览
void view(Data* pd)
{
	printf("\n		--------【显示球员信息】--------		\n");
	printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
		"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
	for (int i = 0; i < pd->size; i++)
		printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n", 
			pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
			pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
	printf("\n");
	printf("共有%d人\n\n\n", pd->size);
	system("pause");   //暂停
	system("cls");     //清屏
	menu();

}
//查询
void inquire(Data* pd)
{
	printf("\n --------【查询球员信息】--------\n");
	int t, f;
	printf("请输入查询方式：1.按编号查询  2.按姓名查询\n");
	scanf("%d", &t);
	switch (t)
	{
	case 0: main();
		break;
	case 1: printf("\n按编号查询\n");
		inquire_num(pd);
		break;
	case 2: printf("\n按姓名查询\n");
		inquire_name(pd);
		break;
	default:
		printf("输入错误!!\n");
		break;
	}
	system("pause");   //暂停
	system("cls");     //清屏
	menu();

}

//按姓名查询
void inquire_name(Data* pd)
{
	system("cls");
	printf("\n	--------【按姓名查询】--------\n");
	char name1[20]={'\0'};
	int flag = 0;
	printf("\n请输入要查找的姓名:  ");
	scanf("%s", name1);
	for (int i = 0; i < pd->size; i++)
	{
		if (strcmp(pd->a[i].name, name1) == 0)
		{
			if (!flag)
			{
				flag = 1;
				printf("找到以下信息：\n");
			}
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
		}
	}
	if (!flag)
	{
		printf("没有找到相关球员\n");
	}
}

//按编号查询
void inquire_num(Data* pd)
{
	system("cls");
	printf("\n --------【按编号查询】--------\n");
	int num = 0;
	int flag = 0;
	printf("\n请输入球员的编号:  ");
	scanf("%d", &num);
	for (int i = 0; i < pd->size; i++)
	{
		if (num == pd->a[i].num)
		{
			flag = 1;
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
		}
	}
	if (!flag)
	{
		printf("没有找到相关球员\n");
	}
}
//删除
void del(Data* pd)
{
	int num = 0;
	printf("请输入要删除球员的编号：");
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < pd->size; i++)
	{
		if (num == pd->a[i].num)
			break;
	}
	for (int j = i; j < pd->size-1; j++)
	{
		pd->a[j] = pd->a[j + 1];
	}
	if (i < pd->size)
	{
		pd->size--;
		printf("成功删除\n");
	}
	system("pause");
	system("cls");
	menu();
}

//添加
void add(Data* pd)
{
	int n = 0;
	int num = 0;
	printf("\n--------【添加球员信息】--------\n");
	printf("请输入本次要添加的球员的数量:");
	scanf("%d", &n);
	for (int i=0;i<n;i++)
	{
		printf("请输入第%d个球员的信息： \n", i+1);
		printf("请输入编号： ");
		scanf("%d", &num);
		for (int j = 0; j < pd->size; j++)
		{
			if (pd->a[j].num == num)
			{
				printf("此编号已存在，请重新输入：", num);
				scanf("%d", &num);
				j = -1;
			}
		}
		isfull(pd);
		pd->a[i].num = num;
		printf("请输入姓名：  ");
		scanf("%s", pd->a[i].name);
		printf("请输入性别：  ");
		getchar();
		scanf("%s", &pd->a[i].gender);
		printf("请输入年龄：  ");
		scanf("%d", &pd->a[i].age);
		printf("请输入身高：  ");
		scanf("%s", &pd->a[i].height);
		printf("请输入工资：  ");
		scanf("%f", &pd->a[i].wages);
		printf("请输入住址：  ");
		scanf("%s", &pd->a[i].addr);
		printf("请输入电话：  ");
		scanf("%s", &pd->a[i].Tel);
		pd->size++;
		system("cls");
		printf("\n创建成功！\n");
	}
	save(pd);
	system("cls");
	printf("\n创建完成!  \n");
	view(pd);
}



//修改
void revise(Data* pd)
{
	printf("\n--------【修改球员信息】--------\n");
	char name[20]={'\0'};
	int  c=0, i=0, n=0, flag = 0;
	printf("\n");
	printf("请输入待修改球员姓名：");
	scanf("%s", name);
	system("cls");
	for (i = 0; i < pd->size; i++)
	{
		if (strcmp((pd->a)[i].name, name) == 0)
		{
			flag = 1;
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
			printf("\n确认修改请按1，取消修改请按0：\n");
			scanf("%d", &n);
			if (n == 1)
			{
				do
				{
					printf("**************************************************\n");
					printf("**	 1.修改编号	**	2.修改姓名	**\n");
					printf("**	 3.修改年龄	**	4.修改身高	**\n");
					printf("**	 5.修改工资	**	6.修改住址	**\n");
					printf("**	 7.修改性别	**	8.修改电话	**\n");
					printf("**	 0.返回主菜单	**			**\n");
					printf("**************************************************\n");
					printf("请输入菜单编号:\n");
					scanf("%d", &c);
					int num1 = 0;
					switch (c)
					{
					case 1:
						printf("原来的编号为：%d\n", pd->a[i].num);
						printf("请输入新的编号：");
						scanf("%d", &num1);
						for (int j = 0; j < pd->size; j++)
						{
							if (pd->a[j].num == num1&&j!=i)	//判断球员编号是否重复
							{
								printf("球员编号重复，请重新输入");
								scanf("%d", &num1);
								j = -1;						//输入编号后重新判断

							}
						}
						pd->a[i].num = num1;
						break;

					case 2:
						printf("原来的姓名为：%s\n", pd->a[i].name);
						printf("请输入新的姓名:");
						scanf("%s", &pd->a[i].name);
						break;
					case 3:
						printf("原来的年龄为：%d\n", pd->a[i].age);
						printf("请输入新的年龄:");
						scanf("%d", &pd->a[i].age);
						break;
					case 4:
						printf("原来的身高为：%s\n", pd->a[i].height);
						printf("请输入新的身高:");
						scanf("%s", &pd->a[i].height);
						break;
					case 5:
						printf("原来的工资位为：%f\n", pd->a[i].wages);
						printf("请输入新的工资:");
						scanf("%f", &pd->a[i].wages);
						break;
					case 6:
						printf("原来的地址为：%s\n", pd->a[i].addr);
						printf("请输入新的地址:");
						scanf("%s", &pd->a[i].addr);
						break;
					case 7:
						printf("原来的性别为：%s\n", pd->a[i].gender);
						printf("请输入新的性别:");
						scanf("%s", &pd->a[i].gender);
						break;
					case 8:
						printf("原来的电话为：%s\n", pd->a[i].Tel);
						printf("请输入新的电话:");
						scanf("%s", &pd->a[i].Tel);
						break;
					case 0:
						printf("退至主菜单");
						system("cls");
						break;
					}
					printf("修改成功！\n");
				} while (c);
			}
			else if(n==0)
			{
				printf("取消修改!!\n");
				system("pause");   //暂停
				system("cls");     //清屏
			}
		}
		break;
	}
	if (flag == 0)
	{
		printf("没有找到对应的球员！\n");
		system("pause");   //暂停
		system("cls");     //清屏
	}
}

int cmp_str(const void* s1, const void* s2)
{
	return strcmp(((DataType*)s1)->name, ((DataType*)s2)->name);
}
//排序
void sort(Data* pd)
{
	printf("\n	  --------【信息排序】--------		\n");
	qsort(pd->a, pd->size, sizeof(DataType), cmp_str);
	printf("排序成功\n");
	system("pause");
	system("cls");
}


//数据统计
void statistics(Data* pd)
{
	printf("\n   --------【数据统计】--------		\n");
	int result = 0;//记录选择结果
	int start = 0, end = 0;
	int num = 0; //人数
	printf("按年龄统计请按1，按编号统计请按2：");
	scanf("%d", &result);
	if (result == 1)
		//按年龄统计
	{
		printf("请输入要统计年龄段的起点(包含端点)：");
		scanf("%d", &start);
		printf("请输入要统计年龄段的终点(包含端点)：");
		scanf("%d", &end);
		int flag = 0;
		for (int i = 0; i < pd->size; i++)
		{
			if (pd->a[i].age >= start && pd->a[i].age <= end)
			{
				if (flag == 0)
				{
					printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
						"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
					flag = 1;
				}
				printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
					pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
					pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
				num++;
			}
		}
		printf("共有%d个人在这个范围内\n", num);
	}
	//按编号统计
	else if (result == 2)
	{
		printf("请输入要统计编号的起点(包含端点)：");
		scanf("%d", &start);
		printf("请输入要统计编号的终点(包含端点)：");
		scanf("%d", &end);
		int flag = 0;
		for (int i = 0; i < pd->size; i++)
		{
			if (pd->a[i].num >= start && pd->a[i].num <= end)
			{
				if (flag == 0)
				{
					printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
						"编号", "姓名", "性别", "年龄", "身高", "工资", "住址", "电话");
					flag = 1;
				}
				printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
					pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
					pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
				num++;
			}
		}
		printf("共有%d个人在这个范围内\n", num);
	}
	else
	{
		printf("输入有误！！");
	}
	system("pause");   //暂停
	system("cls");     //清屏
	menu();
}