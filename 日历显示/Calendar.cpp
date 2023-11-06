#include "Calendar.h"
using namespace std;
Calendar::Calendar(int year, int month)
	:year(year), month(month)
{
}

void Calendar::showCalendar()
{
	int sum = 0;//sum变量来记录从公元1年1月1日到给定的年月的总天数，
	//判断闰年
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
	//判断每个月多少天
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				sum += 29;//闰年的二月份有29天
			}
			else
			{
				sum += 28;//平年的2月份有28天
			}
		}
		else
		{
			if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				sum += 30; //4,6,9,11月都为30天
			}
			else
			{
				sum += 31;//剩下的月份都为31天
			}
		}
	}
	sum++;
	//对星期进行排序
	int weakday = sum % 7; //给定的年月的第一天是星期几
	cout << year << "年" << month << "月" << endl;
	//cout << "日      一      二      三      四      五     六 " << endl;
	cout << "日" << "\t" << "一 " << "\t" << "二" << "\t" << "三" << "\t" << "四" << "\t" << "五" << "\t" << "六" << endl;
	//求余，并加上相应的空格
	for (int i = 1; i <= weakday; i++)
	{
		cout << "\t";
	}
	//对1,3,5,7,8,10,12月进行判断
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
		//对4,6,9,11月进行判断
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
			//对是否为闰年的2月进行判断
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
