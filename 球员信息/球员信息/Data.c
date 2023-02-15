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
// ��¼�������λ��ᣬ��¼ʧ�ܺ���Զ��˳���
//int login()
//{
//	long passworld;
//	printf("��ӭ��¼����Ա��Ϣ����ϵͳ��\n");
//	printf("--------����¼�˺š�--------\n");
//	int a = 0;
//	printf("����������:");
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
//			printf("��¼���������꣬��½ʧ��!!");
//		}
//		else
//		{
//			printf("������󣬻���%d�λ��ᣬ���������룡\n", 2 - i);
//		}
//
//	}
//	return a;
//}



//����
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
//����
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

//���
void view(Data* pd)
{
	printf("\n		--------����ʾ��Ա��Ϣ��--------		\n");
	printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
		"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
	for (int i = 0; i < pd->size; i++)
		printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n", 
			pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
			pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
	printf("\n");
	printf("����%d��\n\n\n", pd->size);
	system("pause");   //��ͣ
	system("cls");     //����
	menu();

}
//��ѯ
void inquire(Data* pd)
{
	printf("\n --------����ѯ��Ա��Ϣ��--------\n");
	int t, f;
	printf("�������ѯ��ʽ��1.����Ų�ѯ  2.��������ѯ\n");
	scanf("%d", &t);
	switch (t)
	{
	case 0: main();
		break;
	case 1: printf("\n����Ų�ѯ\n");
		inquire_num(pd);
		break;
	case 2: printf("\n��������ѯ\n");
		inquire_name(pd);
		break;
	default:
		printf("�������!!\n");
		break;
	}
	system("pause");   //��ͣ
	system("cls");     //����
	menu();

}

//��������ѯ
void inquire_name(Data* pd)
{
	system("cls");
	printf("\n	--------����������ѯ��--------\n");
	char name1[20]={'\0'};
	int flag = 0;
	printf("\n������Ҫ���ҵ�����:  ");
	scanf("%s", name1);
	for (int i = 0; i < pd->size; i++)
	{
		if (strcmp(pd->a[i].name, name1) == 0)
		{
			if (!flag)
			{
				flag = 1;
				printf("�ҵ�������Ϣ��\n");
			}
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
		}
	}
	if (!flag)
	{
		printf("û���ҵ������Ա\n");
	}
}

//����Ų�ѯ
void inquire_num(Data* pd)
{
	system("cls");
	printf("\n --------������Ų�ѯ��--------\n");
	int num = 0;
	int flag = 0;
	printf("\n��������Ա�ı��:  ");
	scanf("%d", &num);
	for (int i = 0; i < pd->size; i++)
	{
		if (num == pd->a[i].num)
		{
			flag = 1;
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
		}
	}
	if (!flag)
	{
		printf("û���ҵ������Ա\n");
	}
}
//ɾ��
void del(Data* pd)
{
	int num = 0;
	printf("������Ҫɾ����Ա�ı�ţ�");
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
		printf("�ɹ�ɾ��\n");
	}
	system("pause");
	system("cls");
	menu();
}

//���
void add(Data* pd)
{
	int n = 0;
	int num = 0;
	printf("\n--------�������Ա��Ϣ��--------\n");
	printf("�����뱾��Ҫ��ӵ���Ա������:");
	scanf("%d", &n);
	for (int i=0;i<n;i++)
	{
		printf("�������%d����Ա����Ϣ�� \n", i+1);
		printf("�������ţ� ");
		scanf("%d", &num);
		for (int j = 0; j < pd->size; j++)
		{
			if (pd->a[j].num == num)
			{
				printf("�˱���Ѵ��ڣ����������룺", num);
				scanf("%d", &num);
				j = -1;
			}
		}
		isfull(pd);
		pd->a[i].num = num;
		printf("������������  ");
		scanf("%s", pd->a[i].name);
		printf("�������Ա�  ");
		getchar();
		scanf("%s", &pd->a[i].gender);
		printf("���������䣺  ");
		scanf("%d", &pd->a[i].age);
		printf("��������ߣ�  ");
		scanf("%s", &pd->a[i].height);
		printf("�����빤�ʣ�  ");
		scanf("%f", &pd->a[i].wages);
		printf("������סַ��  ");
		scanf("%s", &pd->a[i].addr);
		printf("������绰��  ");
		scanf("%s", &pd->a[i].Tel);
		pd->size++;
		system("cls");
		printf("\n�����ɹ���\n");
	}
	save(pd);
	system("cls");
	printf("\n�������!  \n");
	view(pd);
}



//�޸�
void revise(Data* pd)
{
	printf("\n--------���޸���Ա��Ϣ��--------\n");
	char name[20]={'\0'};
	int  c=0, i=0, n=0, flag = 0;
	printf("\n");
	printf("��������޸���Ա������");
	scanf("%s", name);
	system("cls");
	for (i = 0; i < pd->size; i++)
	{
		if (strcmp((pd->a)[i].name, name) == 0)
		{
			flag = 1;
			printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
				"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
			printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
				pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
				pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
			printf("\nȷ���޸��밴1��ȡ���޸��밴0��\n");
			scanf("%d", &n);
			if (n == 1)
			{
				do
				{
					printf("**************************************************\n");
					printf("**	 1.�޸ı��	**	2.�޸�����	**\n");
					printf("**	 3.�޸�����	**	4.�޸����	**\n");
					printf("**	 5.�޸Ĺ���	**	6.�޸�סַ	**\n");
					printf("**	 7.�޸��Ա�	**	8.�޸ĵ绰	**\n");
					printf("**	 0.�������˵�	**			**\n");
					printf("**************************************************\n");
					printf("������˵����:\n");
					scanf("%d", &c);
					int num1 = 0;
					switch (c)
					{
					case 1:
						printf("ԭ���ı��Ϊ��%d\n", pd->a[i].num);
						printf("�������µı�ţ�");
						scanf("%d", &num1);
						for (int j = 0; j < pd->size; j++)
						{
							if (pd->a[j].num == num1&&j!=i)	//�ж���Ա����Ƿ��ظ�
							{
								printf("��Ա����ظ�������������");
								scanf("%d", &num1);
								j = -1;						//�����ź������ж�

							}
						}
						pd->a[i].num = num1;
						break;

					case 2:
						printf("ԭ��������Ϊ��%s\n", pd->a[i].name);
						printf("�������µ�����:");
						scanf("%s", &pd->a[i].name);
						break;
					case 3:
						printf("ԭ��������Ϊ��%d\n", pd->a[i].age);
						printf("�������µ�����:");
						scanf("%d", &pd->a[i].age);
						break;
					case 4:
						printf("ԭ�������Ϊ��%s\n", pd->a[i].height);
						printf("�������µ����:");
						scanf("%s", &pd->a[i].height);
						break;
					case 5:
						printf("ԭ���Ĺ���λΪ��%f\n", pd->a[i].wages);
						printf("�������µĹ���:");
						scanf("%f", &pd->a[i].wages);
						break;
					case 6:
						printf("ԭ���ĵ�ַΪ��%s\n", pd->a[i].addr);
						printf("�������µĵ�ַ:");
						scanf("%s", &pd->a[i].addr);
						break;
					case 7:
						printf("ԭ�����Ա�Ϊ��%s\n", pd->a[i].gender);
						printf("�������µ��Ա�:");
						scanf("%s", &pd->a[i].gender);
						break;
					case 8:
						printf("ԭ���ĵ绰Ϊ��%s\n", pd->a[i].Tel);
						printf("�������µĵ绰:");
						scanf("%s", &pd->a[i].Tel);
						break;
					case 0:
						printf("�������˵�");
						system("cls");
						break;
					}
					printf("�޸ĳɹ���\n");
				} while (c);
			}
			else if(n==0)
			{
				printf("ȡ���޸�!!\n");
				system("pause");   //��ͣ
				system("cls");     //����
			}
		}
		break;
	}
	if (flag == 0)
	{
		printf("û���ҵ���Ӧ����Ա��\n");
		system("pause");   //��ͣ
		system("cls");     //����
	}
}

int cmp_str(const void* s1, const void* s2)
{
	return strcmp(((DataType*)s1)->name, ((DataType*)s2)->name);
}
//����
void sort(Data* pd)
{
	printf("\n	  --------����Ϣ����--------		\n");
	qsort(pd->a, pd->size, sizeof(DataType), cmp_str);
	printf("����ɹ�\n");
	system("pause");
	system("cls");
}


//����ͳ��
void statistics(Data* pd)
{
	printf("\n   --------������ͳ�ơ�--------		\n");
	int result = 0;//��¼ѡ����
	int start = 0, end = 0;
	int num = 0; //����
	printf("������ͳ���밴1�������ͳ���밴2��");
	scanf("%d", &result);
	if (result == 1)
		//������ͳ��
	{
		printf("������Ҫͳ������ε����(�����˵�)��");
		scanf("%d", &start);
		printf("������Ҫͳ������ε��յ�(�����˵�)��");
		scanf("%d", &end);
		int flag = 0;
		for (int i = 0; i < pd->size; i++)
		{
			if (pd->a[i].age >= start && pd->a[i].age <= end)
			{
				if (flag == 0)
				{
					printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
						"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
					flag = 1;
				}
				printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
					pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
					pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
				num++;
			}
		}
		printf("����%d�����������Χ��\n", num);
	}
	//�����ͳ��
	else if (result == 2)
	{
		printf("������Ҫͳ�Ʊ�ŵ����(�����˵�)��");
		scanf("%d", &start);
		printf("������Ҫͳ�Ʊ�ŵ��յ�(�����˵�)��");
		scanf("%d", &end);
		int flag = 0;
		for (int i = 0; i < pd->size; i++)
		{
			if (pd->a[i].num >= start && pd->a[i].num <= end)
			{
				if (flag == 0)
				{
					printf("%-3s\t%-10s\t%-3s\t%-2s\t%-3s\t%-10s\t%-10s\t%-11s\n",
						"���", "����", "�Ա�", "����", "���", "����", "סַ", "�绰");
					flag = 1;
				}
				printf("\n%-3d\t%-10s\t%-3s\t%-2d\t%-3s\t%-6.2f\t%-10s\t%-11s\n",
					pd->a[i].num, pd->a[i].name, pd->a[i].gender, pd->a[i].age, pd->a[i].height,
					pd->a[i].wages, pd->a[i].addr, pd->a[i].Tel);
				num++;
			}
		}
		printf("����%d�����������Χ��\n", num);
	}
	else
	{
		printf("�������󣡣�");
	}
	system("pause");   //��ͣ
	system("cls");     //����
	menu();
}