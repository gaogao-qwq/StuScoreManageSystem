#include "StuScoreManageSystem.h"

void Welcome()
{
	char str[251]={"欢迎使用学生成绩管理系统 by gaogao_qwq，\n\n\t\t\t\t本系统用于学生成绩管理\n\n\n\t\tWelcome to use Student Score Manage System by gaogao_qwq\n\n"};
		
	printf("\n=================================================================================\n");
	printf("\n\n\n\t\t\t");
	for (int i = 0; str[i] != 0; i++)
	{
		Sleep(30); //sleep函数，让程序挂起一段时间，此处用于控制输出s的内容的间隔时间，Windows下括号内时间为毫秒linux下为秒
		printf("%c",str[i]);
	}
	printf("=================================================================================\n");
	system("pause");
}

int Menu()
{
	int choice;
	system("title 学生成绩管理系统 by gaogao_qwq");
	printf("\n\n");
	printf("\t\t\t                           学生成绩管理系统\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                               主菜单                                       *\n");
	printf("\t\t\t*                1.  输入成绩                                                *\n");
	printf("\t\t\t*                2.  计算每门课程的总分和平均分                              *\n");
	printf("\t\t\t*                3.  计算每位学生的总分和平均分                              *\n");
	printf("\t\t\t*                4.  按每个学生的总分由高到低排出名次表                      *\n");
	printf("\t\t\t*                5.  按每个学生的总分由低到高排出名次表                      *\n");
	printf("\t\t\t*                6.  按学号由小到大排出成绩表                                *\n");
	printf("\t\t\t*                7.  按姓名的字典顺序排出成绩表                              *\n");
	printf("\t\t\t*                8.  按学号查询学生排名及其考试成绩                          *\n");
	printf("\t\t\t*                9.  按姓名查询学生排名及其考试成绩                          *\n");
	printf("\t\t\t*                10. 按科目及分数层比例输出                                  *\n");
	printf("\t\t\t*                11. 打印成绩表                                              *\n");
	printf("\t\t\t*                12. 将每个学生的纪录信息写入文件                            *\n");
	printf("\t\t\t*                13. 从文件中读出每个学生的纪录信息并显示                    *\n");
	printf("\t\t\t*                0.  退出程序                                                *\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************请输入你的选择:");
	scanf("%d", &choice);
	return choice;

}

STU *Create(int stuNum, int courseNum) {
	STU *head;
	STU *p1, *p2;
	for (int i = 1; i < stuNum + 1; i++)
	{
		//动态分配
		p1 = (STU *)malloc(LEN);
		printf("\t\t\tID:");
		scanf("%ld", &p1->num);
		printf("\t\t\tname:");
		scanf("%s", p1->name);
		for (int j = 0; j < courseNum; j++)
		{
			printf("\t\t\tscore%d:", j + 1);
			scanf("%f", &p1->score[j]);
		}
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return (head);
}

void AverSumofEveryCourse(STU *head, int stuNum, int courseNum)
{
	STU *p;
	int i, j = 1;
	char ch;
	float sum;
	p = head;
	if (head != NULL)
	{
		printf("\t\t\t******************************************************************************\n");
		for (i = 0; i < courseNum; i++)
		{
			p = head;
			sum = 0.0;

			do
			{
				sum += p->score[i];
				p = p->next;
			} while (p != NULL);
			
			printf("\t\t\tcourse %d:    sum=%.0f , aver=%.0f\n", j, sum, sum / stuNum);
			j++;
		}
		printf("\t\t\t******************************************************************************\n");

	}
}

void AverSumofEveryStudent(STU *head, int stuNum, int courseNum)
{
	STU *p;
	p = head;
	if (head != NULL)
	{
		printf("\n\n\n");
		printf("\t\t\t******************************************************************************\n");
		for (int i = 0; i < stuNum; i++)
		{
			//计算每位学生总成绩
			p->sum = 0.0;
			for (int j = 0; j < courseNum; j++)
			{
				p->sum += p->score[j];
			}
			//计算每位学生平均成绩
			p->aver = p->sum / courseNum;
			//打印
			printf("\t\t\tstudent %d:    sum=%.0f , aver=%.0f\n", p->num, p->sum, p->aver);
			//移到下一节点
			p = p->next;
		}
		printf("\t\t\t******************************************************************************\n");
	}
}

STU *SortbyScoreDescending(STU *head, int stuNum)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;		   //增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum < p1->next->next->sum) //如果前面的节点键值比后面节点的键值小，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;      //让head指向排序后的第一个节点
	free(p1);          		//释放p1
	p1 = NULL;          	//p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}

STU *SortbyScoreAscending(STU *head, int stuNum)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum > p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}

STU *SortbyNum(STU *head)
{
	STU *first;    //为原链表剩下用于直接插入排序的节点头指针
	STU *t;        //临时指针变量：插入节点
	STU *p, *q;     //临时指针变量

	first = head->next;      //原链表剩下用于直接插入排序的节点链表：可根据图12来理解
	head->next = NULL;       //只含有一个节点的链表的有序链表：可根据图11来理解

	while (first != NULL)        //遍历剩下无序的链表
	{
		//注意：这里for语句就是体现直接插入排序思想的地方
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //无序节点在有序链表中找插入的位置

		first = first->next; //无序链表中的节点离开，以便它插入到有序链表中

		if (q == head)      //插在第一个节点之前
		{
			head = t;
		}
		else            //p是q的前驱
		{
			p->next = t;
		}
		t->next = q;     //完成插入动作
		//first = first->next;
	}
	return head;
}

STU *SortbyName(STU *head, int stuNum)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;            //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                  //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name) > 0)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;        //结合第4点理解
				p = p1->next->next;   //结合第6点理解
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}

void Print(STU *head, int stuNum, int courseNum)
{
	STU *p;
	p = head;

	if (head != NULL)        //只要不是空链表，就输出链表中所有节点
	{
		printf("\t\t\t******************************************************************************\n");
		do
		{

			printf("\t\t  %8ld%12s", p->num, p->name);
			//每科成绩
			for (int i = 0; i < courseNum; i++)
			{
				printf("%8.0f", p->score[i]);
			}
			//总成绩及平均分
			printf("%8.0f%8.0f\n", p->sum, p->sum / courseNum);
			p = p->next;     //移到下一个节点
		} while (p != NULL);
		printf("\t\t\t******************************************************************************\n");
	}
}

void SearchbyNum(STU *head, int stuNum, int courseNum)
{
	long num;
	int i;
	int isNull = true;
	printf("\t\t\t");
	scanf("%ld", &num);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t  ");
				printf("%8ld%12s", p->num, p->name);
				for (i = 0; i < courseNum; i++)
				{
					printf("%8.0f", p->score[i]);
				}
				printf("%8.0f%8.0f\n", p->sum, p->sum / courseNum);
				isNull = false;
			}
			p = p->next;
		} while (p != NULL);
		if (isNull)
		{
			printf("\t\t\t");
			printf("学生学号不存在!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}

void SearchbyName(STU *head, int stuNum, int courseNum)
{
	char name[MAX_LEN];
	bool isNull = true;
	printf("\t\t\t");
	scanf("%s", name);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do
		{
			if (strcmp(name, p->name) == 0)
			{
				printf("\t\t  ");
				printf("%8ld%12s", p->num, p->name);
				//打印每科成绩
				for (int i = 0; i < courseNum; i++)
				{
					printf("%8.0f", p->score[i]);
				}
				printf("%8.0f%8.0f\n", p->sum, p->sum / courseNum);
				isNull = false;
			}
			p = p->next;

		} while (p != NULL);
		if (isNull)
		{
			printf("\t\t\t");
			printf("学生姓名不存在!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}

void StatisticAnalysis(STU *head, int stuNum, int courseNum)
{
	int a[6];
	STU *p;
	p = head;
	int i, j;
	for (i = 0; i < courseNum; i++)
	{
		p = head; // 不要忘了初始化，不然会炸
		for (j = 0; j < 6; j++) // 初始化
		{
			a[j] = 0;
		}
		do
		{
			if (p->score[i]<60)
			{
				a[0]++;
			}
			else if (p->score[i]<70)
			{
				a[1]++;
			}
			else if (p->score[i]<80)
			{
				a[2]++;
			}
			else if (p->score[i]<90)
			{
				a[3]++;
			}
			else if (p->score[i]<100)
			{
				a[4]++;
			}
			else
			{
				a[5]++;
			}

			p = p->next;

		} while (p != NULL);
		printf("\n\n\n");
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t* For course %d:\n", i + 1);
		printf("\t\t\t* <60\t%d\t%.2f%%\n", a[0], 100 * a[0] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 60, 69, a[1], 100 * a[1] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 70, 79, a[2], 100 * a[2] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 80, 89, a[3], 100 * a[3] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 90, 99, a[4], 100 * a[4] / 6.0);
		printf("\t\t\t* %d\t%d\t%.2f%%\n", 100, a[5], 100 * a[5] / 6.0);
		printf("\t\t\t******************************************************************************\n");

	}
}

void WritetoFile(STU *head, int stuNum, int courseNum)
{
	STU *p;
	p = head;
	FILE *fp;
	int i, j;
	printf("\n\n\n");
	printf("\t\t\t******************************************************************************\n");

	//写失败则提前返回值
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("\t\t\t导出失败!\n");
		return;
	}

	fprintf(fp, "%d\t%d\n", stuNum, courseNum);
	for (i = 0; i < stuNum; i++)
	{
		fprintf(fp, "%12ld%12s", p->num, p->name);
		for (j = 0; j < courseNum; j++)
		{
			fprintf(fp, "%12.0f", p->score[j]);
		}
		fprintf(fp, "%12.0f%12.0f\n", p->sum, p->sum / courseNum);

		p = p->next;
	}
	printf("\t\t\t导出成功!\n");
	fclose(fp);
	printf("\t\t\t******************************************************************************\n");

}

/*
void ReadfromFile(STU1 stu[], int *n, int *m)
{
FILE *fp;
int i, j;
printf("\n\n\n");
printf("\t\t\t******************************************************************************\n");
if ((fp = fopen("student.txt", "r")) == NULL)
{
printf("\t\t\tFail to open student.txt\n");
return;
}
fscanf(fp, "%d\t%d\n", n, m);
for (i = 0; i<*n; i++)
{
fscanf(fp, "%12ld", &stu[i].num);
fscanf(fp, "%12s", stu[i].name);
for (j = 0; j<*m; j++)
{
fscanf(fp, "%12f", &stu[i].score[j]);
}
fscanf(fp, "%12f%12f", &stu[i].sum, &stu[i].aver);

}
printf("\t\t\tImport Successfully!\n");
fclose(fp);


for (i = 0; i < *n; i++)
{
printf("\t\t\t%ld\t%s\t", stu[i].num, stu[i].name);
for (j = 0; j<*m; j++)
{
printf("%.0f\t", stu[i].score[j]);
}
printf("%.0f\t%.0f\n", stu[i].sum, stu[i].aver);
}

printf("\t\t\t******************************************************************************\n");

}
*/

//这里直接生成了一个新的链表Create_，确保可以直接读取存好的数据
STU *Create_(int n, int m)
{
	STU *head;
	STU *p1, *p2;
	// system("cls");
	for (int i = 1; i < n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}

STU *ReadfromFile(STU *head, int *stuNum, int *courseNum)
{
	STU *p;
	FILE *fp;
	int i, j;

	//读失败则提前返回值
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("\t\t\t找不到或无法打开student.txt\n");
		return NULL;
	}

	fscanf(fp, "%d\t%d\n", stuNum, courseNum);
	head = Create_(*stuNum, *courseNum); //创建了一个空链表，并且赋给head
	p = head;
	for (i = 0; i < *stuNum; i++)
	{
		fscanf(fp, "%12ld", &p->num);
		fscanf(fp, "%12s", &p->name);
		for (j = 0; j < *courseNum; j++)
		{
			fscanf(fp, "%12f", &p->score[j]);
		}
		fscanf(fp, "%12f%12f", &p->sum, &p->aver);

		p = p->next;

	}
	i = *stuNum;
	j = *courseNum;
	printf("\t\t\t导入成功!\n");
	fclose(fp);

	Print(head, i, j);

	return head;
}