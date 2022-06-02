#include "StuScoreManageSystem.h"

int main()
{
	int n, m;
	int i;
	STU *head;  //定义头节点
	head = (STU *)malloc(LEN);
	while (1)
	{
		i = Menu();
		if (i == 1)
		{
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):\n"); //输入学生数
			printf("\t\t\t");
			scanf("%d", &n);
			printf("\t\t\tInput course number(m<=6):\n");
			printf("\t\t\t");
			scanf("%d", &m);
		}
		switch (i)
		{
		case 1:
			printf("\t\t\tInput student's ID, name and score:\n");
			head = Creat(n, m);
			system("cls");  //清屏
			break;
		case 2:
			system("cls");  //清屏
			AverSumofEveryStudent(head, n, m);
			break;
		case 3:
			system("cls");  //清屏
			AverSumofEveryCourse(head, n, m);
			break;
		case 4:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			head = SortbyScore(head, n);
			Print(head, n, m);
			break;
		case 5:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			head = SortbyScore1(head, n);
			Print(head, n, m);
			break;
		case 6:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			break;
		case 7:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);
			Print(head, n, m);
			break;
		case 8:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			break;
		case 9:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			break;
		case 10:
			system("cls");  //清屏
			StatisticAnalysis(head, n, m);
			break;
		case 11:
			system("cls");  //清屏
			printf("\n\n\n");
			Print(head, n, m);
			break;
		case 12:
			system("cls");  //清屏
			WritetoFile(head, n, m);
			break;
		case 13:
			system("cls");  //清屏
			head = ReadfromFile(head, &n, &m);
			break;
		case 0:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tEnd of program!\n");
			printf("\t\t\t******************************************************************************\n");
			return 0;
		default:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");

		}

	}

	return 0;
}