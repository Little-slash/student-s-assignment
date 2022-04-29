#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
const int N = 1000;
float stu[N],stunum[N];
int CURRENT_N;
void gotoxy(HANDLE obj, int x, int y)         //定义光标的位置 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(obj, pos);
}
void outgood()                 //求高分的标识 
{
	cout << R"(            
	            _   
	           | \
	          /   |
	  _______/    |__
	||     ||       _|
	||     ||      |_
	||     ||       _|
	||     ||      |_ 
	||_____|| _______|     求同学给个高分)";
}
void out(HANDLE obj)                 //输出整体 
{
	int x = 27, y =8;
	gotoxy(obj,x, y);
	cout << " ----------------------------------------------------";
	gotoxy(obj, x-1, y + 1);
	cout << "|                                                     |";
	gotoxy(obj, x-1, y + 2);
	cout << "|            欢迎使用lfh版成绩管理系统                |";
	gotoxy(obj, x-1, y + 3);
	cout << "|        1=录入学生          2=显示信息               |";
	gotoxy(obj, x-1, y + 4);
	cout << "|        3=排序总评          4=查找学生               |";
	gotoxy(obj, x-1, y + 5);
	cout << "|        5=插入学生          6=删除学生               |";
	gotoxy(obj, x-1, y + 6);
	cout << "|        7=统计学生          0=退出系统               |";
	gotoxy(obj, x - 1, y + 7);
	cout << "|                                                     |";
	gotoxy(obj, x - 1, y + 8);
	cout << "|                                                     |";
	gotoxy(obj, x, y + 9);
	cout << " ---------------------------------------------------";
}
int findnum(int x, int r)           //自定义寻找函数：直接遍历 
{
	for (int i = 0; i <= r; i++)
	{
		if (stu[i] == x) return x;
	}
	return -1;
}
void input1(HANDLE obj)           //录入学生：while循环 
{
	while (1)
	{
		system("cls"); 
		gotoxy(obj, 0, 0);
		outgood();
		gotoxy(obj, 40, 21);
		cout << "请输入成绩（0~100）：";
		float x;
		cin >> x;
		if (x < 0 || x>100) cout << "输入错误，数据应在0~100之间"<<endl;
		else stu[CURRENT_N++] = x;
		if (CURRENT_N >= N-1)
		{
			cout << "已达到人数上限，无法输入，将在一秒后返回";
			Sleep(1000);
			return;
		}
		char choose;
		cout << "请问您是否继续输入（Y/N）：";
		cin >> choose;
		if (choose == 'N') return;
	}
}
void find1(HANDLE obj)             //查找学生 ：直接遍历 
{
	while (1) {
		float x;
		cin >> x;
		int q = findnum(x, CURRENT_N - 1);
		cout << endl;
		if (q == -1) cout << "未找到该学生成绩" << endl;
		else cout <<"查询到第一个符合条件的数字为："<< x << endl;
		cout << "请问是否继续寻找：（Y/N）";
		char choose;
		cin >> choose;
		if (choose == 'N') return;
		system("cls");
	}
}
void quick_sort(float stu[], int l, int r)      //快速排序 
{
	if (l >= r) return;
	int i = l - 1, j = r + 1, q = stu[l + r >> 1];
	while (i < j)
	{
		do i++; while (stu[i] > q);
		do j--; while (stu[j] < q);
		if (i < j) swap(stu[i], stu[j]);
	}
	quick_sort(stu, l, j), quick_sort(stu, j + 1, r);
}
void output1(float stu[], int r)       //普通输出   output1(float stu[],int r)
{
	if (r == 0) cout << "未输入信息";
	for (int i = 0; i < r; i++)
	{
		cout<<stu[i]<<" ";
	}
}
void output2(int r)      //排序统计 output2(int r)
{
    float a[N]{};
	for (int i = 0; i <= r; i++) a[i] = stu[i];
	quick_sort(a, 0, r);
	output1(a, r+1);
}
void del(int x, int r)      //自定义删除函数 del(int x,int r)
{
	int sys = 0;
	for (int i = 1; i <= r; i++)
	{
		if (stu[i] == x)
		{
			for (int j = i; j <= r; j++)
			{
				stu[i] = stu[i + 1];
			}
			stu[r] = 0;
			CURRENT_N--;
			sys = 1;
		}
	}
	if(sys==0) cout << "没有该学生信息";
}
void insert_sort()         //插入删除函数 
{
	float a[N]{};
	for (int i = 0; i < CURRENT_N; i++) a[i] = stu[i];
	quick_sort(a, 0, CURRENT_N-1);
	cout<<"目前存在的数字为：";
	output1(a, CURRENT_N);
	int m;
	while(1)
	{
		cout<<"请输入你想插入的成绩：";
		cin>>m;
		stu[CURRENT_N++] = m;
		cout<<endl;
		cout<<"插入后为：";
		output2(CURRENT_N-1);
		char choose;
		cout<<"请问你是否继续插入(Y/N):";
		if(choose=='N') return ;
		system("cls");
	}
 } 
void count()                    //统计学生 
{
	cout << endl;
	int a[5] = { 0 };
	for (int i = 0; i <= CURRENT_N - 1; i++)
	{
		if (stu[i] <= 100 && stu[i] > 90) a[0]++;
		else if (stu[i] <= 90 && stu[i] > 80) a[1]++;
		else if (stu[i] <= 90 && stu[i] > 70) a[2]++;
		else if (stu[i] <= 90 && stu[i] > 60) a[3]++;
		else if (stu[i] <= 60) a[4]++;
	}
	cout << setw(10) << "100~90" << setw(10) << "90~80" << setw(10) << "80~70" << setw(10) << "70~60" << setw(10) << "60~0" << endl;
	cout << setw(10) << "    " << a[0] << setw(10) << "    " << a[1] << setw(10) << "    " << a[2] << setw(10) << "    " << a[3] << setw(10) << "    " << a[4];
}
void del1()
{
	while (1)
	{
		float x;
		cout << "请输入你想删除的数字：";
		cin >> x;
		del(x, CURRENT_N - 1);
		cout << endl;
		cout << "是否继续删除：(Y/N)";
		char choose;
		cin >> choose;
		if (choose == 'N') return;
	}
}
int main()
{
	SetConsoleTitle("欢迎使用lfh成绩管理系统");
	HANDLE scr = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(scr, 40, 25);
	outgood();
	Sleep(1000);
	system("cls");
	gotoxy(scr, 44, 15);
	cout << "欢迎使用lfh版本学生管理系统" << endl;
	gotoxy(scr, 47, 16);
	cout << "点击enter键继续";
	_getch();
	system("cls");
	out(scr);

	int m;
	while (1)
	{
		out(scr);
		gotoxy(scr, 25, 20);
		cout << "请输入您的选择：";
		cin >> m;

		if (m == 0) {
			system("cls");
			gotoxy(scr, 40, 21);
			cout << "成功退出";
			Sleep(1000);
			return 0;
		}
		else if (m == 1)
		{
			input1(scr);
			system("cls");
		}
		else if (m == 2)
		{
			output1(stu,CURRENT_N);
			cout << endl; cout << endl;
			cout << "点击enter继续操作";
			_getch();
			system("cls");
		}
		else if (m == 3)
		{
			system("cls");
			gotoxy(scr, 40 ,16);
			output2(CURRENT_N - 1);
			_getch();
			system("cls");
		 }
		else if (m == 4)
		{
			system("cls");
			find1(scr);
			_getch();
			system("cls");
		 }
		else if (m == 5)
		{
			insert_sort();
			system("cls");
		 }
		else if (m == 6)
		{
			del1();
			system("cls");
		 }
		else if (m == 7)
		{
			count();
			cout<<endl;
			cout << "点击enter继续操作";
			_getch();
			system("cls");
		 }
	}
	return 0;
}


