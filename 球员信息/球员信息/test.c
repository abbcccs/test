#define _CRT_SECURE_NO_WARNINGS 1

#include"Data.h"


//�˵�
void menu()
{
	printf("		  ��ӭ���롶��Ա��Ϣ����ϵͳ��  \n");
	printf("******************************************************************\n");
	printf("**	1.��ʾ��Ա��Ϣ		**	2.�����Ա��Ϣ		**\n");
	printf("**	3.�޸���Ա��Ϣ		**	4.ɾ����Ա��Ϣ		**\n");
	printf("**	5.������Ա��Ϣ		**	6.����Ա����		**\n");
	printf("**	7.ͳ����Ա��Ϣ		**	0.�˳�ϵͳ		**\n");
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
		printf("��ѡ��˵����:");
		scanf("%d", &num);
		system("cls");     //����
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
			printf("�˳�ϵͳ\n");
			exit(0);
			break;
		default:printf("��ѡ��˵��");
		}
		printf("\n");
		system("cls");
	} while (num);
	//if (login() == 1)
	//{
	//	printf("��½�ɹ�\n");
	//	system("pause");   //��ͣ
	//	system("cls");     //����
	//	
	//}
	return 0;
}


