#include "StuScoreManageSystem.h"

int main()
{
	int stuNum, courseNum;
	int choice;
	STU *head;  //定义头节点
	head = (STU *)malloc(LEN);

	Welcome();
	
	while (true)
	{
		choice = MainMenu();
		switch (choice)
		{
		case 1:
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");

			//输入学生数
			printf("\t\t\tInput student number(n<30):\n");
			printf("\t\t\t");
			scanf("%d", &stuNum);

			//输入学科数
			printf("\t\t\tInput course number(m<=6):\n");
			printf("\t\t\t");
			scanf("%d", &courseNum);

			//输入学生学号、姓名、分数
			printf("\t\t\tInput student's ID, name and score:\n");
			head = Create(stuNum, courseNum);

			//计算每名学生和每个学科成绩的总和及平均分
			AverSumofEveryCourse(head, stuNum, courseNum);
			AverSumofEveryStudent(head, stuNum, courseNum);

			system("cls");  //清屏
			break;
		case 2:
			system("cls");  //清屏
			EditMenu(head, stuNum, courseNum);
			break;
		case 3:
			system("cls");  //清屏
			SortMenu(head, stuNum, courseNum);
			break;
		case 4:
			system("cls");  //清屏
			SearchMenu(head, stuNum, courseNum);
			break;
		case 5:
			system("cls");  //清屏
			PrintMenu(head, stuNum, courseNum);
			break;
		case 6:
			system("cls");  //清屏
			head = ReadfromFile(head, &stuNum, &courseNum);
			break;
		case 7:
			system("cls");  //清屏
			WritetoFile(head, stuNum, courseNum);
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