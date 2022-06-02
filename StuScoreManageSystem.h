#include<stdio.h>
#include<string.h>
#include<math.h>
#include <malloc.h>
#include <stdlib.h>

#define   MAX_LEN  10                	   // 字符串最大长度
#define   STU_NUM 30                       // 最多的学生人数
#define   COURSE_NUM 6                     // 最多的考试科目数
#define   LEN sizeof(struct Student)

typedef struct Student
{
	long num;	                    // 每个学生的学号
	char name[MAX_LEN];            	// 每个学生的姓名
	float score[COURSE_NUM];	    // 每个学生COURSE_NUM门功课的成绩
	float sum;                      // 每个学生的总成绩
	float aver;						// 每个学生的平均成绩
	struct Student *next;
}STU;

//菜单函数
int Menu(void);

//打印函数
void Print(STU *head, int n, int m);

//计算每门课程的总分和平均分
void AverSumofEveryStudent(STU *head, int n, int m);

//计算每个学生的总分和平均分
void AverSumofEveryCourse(STU *head, int n, int m);

//按每个学生的总分由高到低排出名次表
STU *SortbyScore(STU *head, int n);

//创建链表并录入信息
STU *Creat(int n, int m);
STU *Creat1(int n, int m);

//按每个学生的总分由低到高排出名次表
STU *SortbyScore1(STU *head, int n);

//按学号由小到大排出成绩表
STU *SortbyNum(STU *head);

//按姓名的字典顺序排出成绩表
STU *SortbyName(STU *head, int n);

//按学号查询学生排名及其考试成绩
void SearchbyNum(STU *head, int n, int m);

//按姓名查询学生排名及其考试成绩
void SearchbyName(STU *head, int n, int m);

//按类别及比例输出       
void StatisticAnalysis(STU *head, int n, int m);

//将每个学生的纪录信息写入文件
void WritetoFile(STU *head, int n, int m);

//从文件中读出每个学生的纪录信息并显示
STU *ReadfromFile(STU *head, int *n, int *m);