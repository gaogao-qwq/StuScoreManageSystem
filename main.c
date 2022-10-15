#include "StuScoreManageSystem.h"

int main()
{
	int stuNum = 0, courseNum = 0;
	int choice = -1;
	STU *head = NULL;  //定义头节点
	head = (STU *)malloc(LEN); //内存分配

	//Welcome();
	
	while (true)
	{
		choice = MainMenu();
		switch (choice)
		{
		case 1:
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");

			//初始化学生数和科目数函数
			InitInput(&stuNum, &courseNum);

			//输入学生学号、姓名、分数
			printf("\t\t\tInput student's ID, name and score:\n");
			head = Create(stuNum, courseNum);

			//计算每名学生和每个学科成绩的总和及平均分
			AverSumofEveryCourse(head, courseNum);
			AverSumofEveryStudent(head, stuNum, courseNum);

			system("cls");  //清屏
			Print(head, stuNum, courseNum);
			break;
		case 2:
			system("cls");  //清屏
			head = EditMenu(head, &stuNum, courseNum);
			break;
		case 3:
			system("cls");  //清屏
			head = SortMenu(head, stuNum, courseNum);
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