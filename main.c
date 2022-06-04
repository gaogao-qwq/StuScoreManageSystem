#include "StuScoreManageSystem.h"

int main()
{
	int stuNum, courseNum;
	int choice;
	STU *head;  //定义头节点
	head = (STU *)malloc(LEN);

	Welcome();
	
	while (1)
	{
		choice = Menu();

		switch (choice)
		{
		case 1:
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):\n"); //输入学生数
			printf("\t\t\t");
			scanf("%d", &stuNum);
			printf("\t\t\tInput course number(m<=6):\n"); //输入学科数
			printf("\t\t\t");
			scanf("%d", &courseNum);
			printf("\t\t\tInput student's ID, name and score:\n");//输入学生学号、姓名、分数
			head = Create(stuNum, courseNum);
			system("cls");  //清屏
			break;
		case 2:
			system("cls");  //清屏
			AverSumofEveryCourse(head, stuNum, courseNum);
			break;
		case 3:
			system("cls");  //清屏
			AverSumofEveryStudent(head, stuNum, courseNum);
			break;
		case 4:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in descending order by score:\n");
			head = SortbyScoreDescending(head, stuNum);
			Print(head, stuNum, courseNum);
			break;
		case 5:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			head = SortbyScoreAscending(head, stuNum);
			Print(head, stuNum, courseNum);
			break;
		case 6:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by number:\n");
			head = SortbyNum(head);
			Print(head, stuNum, courseNum);
			break;
		case 7:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, stuNum);
			Print(head, stuNum, courseNum);
			break;
		case 8:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, stuNum, courseNum);
			break;
		case 9:
			system("cls");  //清屏
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, stuNum, courseNum);
			break;
		case 10:
			system("cls");  //清屏
			StatisticAnalysis(head, stuNum, courseNum);
			break;
		case 11:
			system("cls");  //清屏
			printf("\n\n\n");
			Print(head, stuNum, courseNum);
			break;
		case 12:
			system("cls");  //清屏
			WritetoFile(head, stuNum, courseNum);
			break;
		case 13:
			system("cls");  //清屏
			head = ReadfromFile(head, &stuNum, &courseNum);
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