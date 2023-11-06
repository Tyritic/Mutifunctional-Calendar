#include "Calendar.h"
using namespace std;
Calendar::Calendar(int year, int month)
	:year(year), month(month)
{
}

void Calendar::showCalendar()
{
	int sum = 0;//sum��������¼�ӹ�Ԫ1��1��1�յ����������µ���������
	//�ж�����
	for (int i = 1; i < year; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			sum = sum + 366;
		}
		else
		{
			sum = sum + 365;
		}
	}
	//�ж�ÿ���¶�����
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				sum += 29;//����Ķ��·���29��
			}
			else
			{
				sum += 28;//ƽ���2�·���28��
			}
		}
		else
		{
			if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				sum += 30; //4,6,9,11�¶�Ϊ30��
			}
			else
			{
				sum += 31;//ʣ�µ��·ݶ�Ϊ31��
			}
		}
	}
	sum++;
	//�����ڽ�������
	int weakday = sum % 7; //���������µĵ�һ�������ڼ�
	cout << year << "��" << month << "��" << endl;
	//cout << "��      һ      ��      ��      ��      ��     �� " << endl;
	cout << "��" << "\t" << "һ " << "\t" << "��" << "\t" << "��" << "\t" << "��" << "\t" << "��" << "\t" << "��" << endl;
	//���࣬��������Ӧ�Ŀո�
	for (int i = 1; i <= weakday; i++)
	{
		cout << "\t";
	}
	//��1,3,5,7,8,10,12�½����ж�
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		for (int i = 1; i <= 31; i++)
		{
			if (sum % 7 == 6)
			{
				cout << i << "\n";
			}
			else
			{
				cout << i << "\t";
			}
			sum++;
		}
	}
	else
		//��4,6,9,11�½����ж�
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			for (int i = 1; i <= 30; i++)
			{
				if (sum % 7 == 6)
				{
					cout << i << "\n";
				}
				else
				{
					cout << i << "\t";
				}
				sum++;
			}
		}
		else
		{
			//���Ƿ�Ϊ�����2�½����ж�
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				for (int i = 1; i <= 29; i++)
				{
					if (sum % 7 == 6)
					{
						cout << i << "\n";
					}
					else
					{
						cout << i << "\t";
					}
					sum++;
				}
			}
			else
			{
				for (int i = 1; i <= 28; i++)
				{
					if (sum % 7 == 6)
					{
						cout << i << "\n";
					}
					else
					{
						cout << i << "\t";
					}
					sum++;
				}
			}
		}
	cout << endl;
}
