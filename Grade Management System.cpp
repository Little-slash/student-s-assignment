#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
const int N = 1000;
float stu[N],stunum[N];
int CURRENT_N;
void gotoxy(HANDLE obj, int x, int y)         //�������λ�� 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(obj, pos);
}
void outgood()                 //��߷ֵı�ʶ 
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
	||_____|| _______|     ��ͬѧ�����߷�)";
}
void out(HANDLE obj)                 //������� 
{
	int x = 27, y =8;
	gotoxy(obj,x, y);
	cout << " ----------------------------------------------------";
	gotoxy(obj, x-1, y + 1);
	cout << "|                                                     |";
	gotoxy(obj, x-1, y + 2);
	cout << "|            ��ӭʹ��lfh��ɼ�����ϵͳ                |";
	gotoxy(obj, x-1, y + 3);
	cout << "|        1=¼��ѧ��          2=��ʾ��Ϣ               |";
	gotoxy(obj, x-1, y + 4);
	cout << "|        3=��������          4=����ѧ��               |";
	gotoxy(obj, x-1, y + 5);
	cout << "|        5=����ѧ��          6=ɾ��ѧ��               |";
	gotoxy(obj, x-1, y + 6);
	cout << "|        7=ͳ��ѧ��          0=�˳�ϵͳ               |";
	gotoxy(obj, x - 1, y + 7);
	cout << "|                                                     |";
	gotoxy(obj, x - 1, y + 8);
	cout << "|                                                     |";
	gotoxy(obj, x, y + 9);
	cout << " ---------------------------------------------------";
}
int findnum(int x, int r)           //�Զ���Ѱ�Һ�����ֱ�ӱ��� 
{
	for (int i = 0; i <= r; i++)
	{
		if (stu[i] == x) return x;
	}
	return -1;
}
void input1(HANDLE obj)           //¼��ѧ����whileѭ�� 
{
	while (1)
	{
		system("cls"); 
		gotoxy(obj, 0, 0);
		outgood();
		gotoxy(obj, 40, 21);
		cout << "������ɼ���0~100����";
		float x;
		cin >> x;
		if (x < 0 || x>100) cout << "�����������Ӧ��0~100֮��"<<endl;
		else stu[CURRENT_N++] = x;
		if (CURRENT_N >= N-1)
		{
			cout << "�Ѵﵽ�������ޣ��޷����룬����һ��󷵻�";
			Sleep(1000);
			return;
		}
		char choose;
		cout << "�������Ƿ�������루Y/N����";
		cin >> choose;
		if (choose == 'N') return;
	}
}
void find1(HANDLE obj)             //����ѧ�� ��ֱ�ӱ��� 
{
	while (1) {
		float x;
		cin >> x;
		int q = findnum(x, CURRENT_N - 1);
		cout << endl;
		if (q == -1) cout << "δ�ҵ���ѧ���ɼ�" << endl;
		else cout <<"��ѯ����һ����������������Ϊ��"<< x << endl;
		cout << "�����Ƿ����Ѱ�ң���Y/N��";
		char choose;
		cin >> choose;
		if (choose == 'N') return;
		system("cls");
	}
}
void quick_sort(float stu[], int l, int r)      //�������� 
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
void output1(float stu[], int r)       //��ͨ���   output1(float stu[],int r)
{
	if (r == 0) cout << "δ������Ϣ";
	for (int i = 0; i < r; i++)
	{
		cout<<stu[i]<<" ";
	}
}
void output2(int r)      //����ͳ�� output2(int r)
{
    float a[N]{};
	for (int i = 0; i <= r; i++) a[i] = stu[i];
	quick_sort(a, 0, r);
	output1(a, r+1);
}
void del(int x, int r)      //�Զ���ɾ������ del(int x,int r)
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
	if(sys==0) cout << "û�и�ѧ����Ϣ";
}
void insert_sort()         //����ɾ������ 
{
	float a[N]{};
	for (int i = 0; i < CURRENT_N; i++) a[i] = stu[i];
	quick_sort(a, 0, CURRENT_N-1);
	cout<<"Ŀǰ���ڵ�����Ϊ��";
	output1(a, CURRENT_N);
	int m;
	while(1)
	{
		cout<<"�������������ĳɼ���";
		cin>>m;
		stu[CURRENT_N++] = m;
		cout<<endl;
		cout<<"�����Ϊ��";
		output2(CURRENT_N-1);
		char choose;
		cout<<"�������Ƿ��������(Y/N):";
		if(choose=='N') return ;
		system("cls");
	}
 } 
void count()                    //ͳ��ѧ�� 
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
		cout << "����������ɾ�������֣�";
		cin >> x;
		del(x, CURRENT_N - 1);
		cout << endl;
		cout << "�Ƿ����ɾ����(Y/N)";
		char choose;
		cin >> choose;
		if (choose == 'N') return;
	}
}
int main()
{
	SetConsoleTitle("��ӭʹ��lfh�ɼ�����ϵͳ");
	HANDLE scr = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(scr, 40, 25);
	outgood();
	Sleep(1000);
	system("cls");
	gotoxy(scr, 44, 15);
	cout << "��ӭʹ��lfh�汾ѧ������ϵͳ" << endl;
	gotoxy(scr, 47, 16);
	cout << "���enter������";
	_getch();
	system("cls");
	out(scr);

	int m;
	while (1)
	{
		out(scr);
		gotoxy(scr, 25, 20);
		cout << "����������ѡ��";
		cin >> m;

		if (m == 0) {
			system("cls");
			gotoxy(scr, 40, 21);
			cout << "�ɹ��˳�";
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
			cout << "���enter��������";
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
			cout << "���enter��������";
			_getch();
			system("cls");
		 }
	}
	return 0;
}


