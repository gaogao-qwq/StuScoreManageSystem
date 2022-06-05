#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define MAX_LEN 12                	     //姓名字符串最大长度
#define STU_NUM 30                       //最多的学生人数
#define COURSE_NUM 6                     //最多的考试科目数
#define LEN sizeof(struct Student)

typedef struct Student
{
	long num;	                    // 每个学生的学号
	char name[MAX_LEN];            	// 每个学生的姓名
	float score[COURSE_NUM];	    // 每个学生COURSE_NUM门功课的成绩
	float sum;                      // 每个学生的总成绩
	float aver;						// 每个学生的平均成绩
	struct Student *next;           //指针域
}STU;

//欢迎语界面函数
void Welcome();

//主菜单函数
int MainMenu();

//编辑成绩表二级菜单函数
void EditMenu(STU *head, int stuNum, int courseNum);

//成绩表排序二级菜单函数
void SortMenu(STU *head, int stuNum, int courseNum);

//查询学生成绩二级菜单函数
void SearchMenu(STU *head, int stuNum, int courseNum);

//打印学生成绩二级菜单函数
void PrintMenu(STU *head, int stuNum, int courseNum);

//创建链表并录入信息函数
STU *Create(int n, int m);

//打印成绩表函数
void Print(STU *head, int n, int m);

//计算每门课程的总分和平均分函数
void AverSumofEveryCourse(STU *head, int n, int m);

//计算每个学生的总分和平均分函数
void AverSumofEveryStudent(STU *head, int n, int m);

//按每个学生的总分由高到低排出名次表函数
STU *SortbyScoreDescending(STU *head, int n);

//按每个学生的总分由低到高排出名次表函数
STU *SortbyScoreAscending(STU *head, int n);

//按学号由小到大排出成绩表函数
STU *SortbyNum(STU *head);

//按姓名的字典顺序排出成绩表函数
STU *SortbyName(STU *head, int n);

//按学号查询学生排名及其考试成绩函数
void SearchbyNum(STU *head, int n, int m);

//按姓名查询学生排名及其考试成绩函数
void SearchbyName(STU *head, int n, int m);

//按学科及分数层比例输出函数      
void StatisticAnalysis(STU *head, int n, int m);

//将每个学生的纪录信息写入文件函数
void WritetoFile(STU *head, int n, int m);

//这里直接生成了一个新的链表Create_，确保可以直接读取存好的数据
STU *Create_(int n, int m);

//从文件中读出每个学生的纪录信息并显示函数
STU *ReadfromFile(STU *head, int *n, int *m);