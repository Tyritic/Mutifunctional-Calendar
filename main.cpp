#pragma warning(disable:4996)；
#pragma once
#include <iostream>
#include <string>
#include"PersonalScheduleList.h"
#include"PersonalScheduleNode.h"
#include"TeamScheduleList.h"
#include"TeamScheduleNode.h"
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include"Student.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include"cJSON/cJSON.h"
#include"Calendar.h"
#include<time.h>
#include"Date.h"
#include"Manager.h"
#include<cmath>
using namespace std;
void LoginIn(string filename, int type);
//全局函数 进入学生子菜单界面
void studentMenu(Identity*& student);
void PersonalStudentcreate(Student*);
void TeamStudentcreate(Student*);
void PersonalStudentfind(Student*);
void TeamStudentfind(Student*);
void PersonalStudentomit(Student*);
void TeamStudentomit(Student*);
void PersonalStudentmodify(Student*);
void TeamStudentmodify(Student*);
//全局函数 进入教师子菜单界面
void PersonalTeachercreate(Teacher*);
void PersonalTeacherfind(Teacher*);
void PersonalTeacheromit(Teacher*);
void PersonalTeachermodify(Teacher*);
void TeamTeachercreate(Teacher*);
void TeamTeacherfind(Teacher*);
void TeamTeacheromit(Teacher*);
void TeamTeachermodify(Teacher*);
void calendarMenu();//日历菜单
//身份菜单
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);
void managerMenu(Identity*& manager);
//个人日程菜单和团体日程菜单
void PersonalMenu();
void TeamMenu();
int LunarCalendar(int year, int month, int day);
//将链表数据保存到个人文件中
void outputToPersonalFile(PersonalScheduleList& sl, string filename);
//将链表数据保存到团队文件中
void outputToTeamFile(TeamScheduleList& sl, string filename);
//从团队文件中读取链表数据
void inputFromTeamFile(TeamScheduleList& sl, string filename);
//从个人文件中读取链表数据
void inputFromPersonalFile(PersonalScheduleList& sl, string filename);
const char* host = "api.seniverse.com";
const char* key = "SmKNAkNDNgy0VQHrh";
const char* language = "zh-Hans";
char _url[100] = { 0 };
SYSTEMTIME sys;      //系统时间参量

unsigned int LunarCalendarDay;
unsigned int LunarCalendarTable[199] =
{


0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A

,/*1901-1910*/


0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754

,/*1911-1920*/


0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E

,/*1921-1930*/


0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48

,/*1931-1940*/


0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51

,/*1941-1950*/


0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x6AD53C

,/*1951-1960*/


0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46

,/*1961-1970*/


0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50

,/*1971-1980*/


0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB

,/*1981-1990*/


0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645

,/*1991-2000*/


0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E

,/*2001-2010*/


0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9

,/*2011-2020*/


0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43

,/*2021-2030*/


0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C

,/*2031-2040*/


0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37

,/*2041-2050*/


0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42

,/*2051-2060*/


0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B

,/*2061-2070*/


0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6

,/*2071-2080*/


0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E

,/*2081-2090*/
	0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5

	/*2091-2099*/
};
int MonthAdd[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
int LunarCalendar(int year, int month, int day)
{
	int Spring_NY, Sun_NY, StaticDayCount;
	int index, flag;
	//Spring_NY 记录春节离当年元旦的天数。
	if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
		Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
	else Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
	Sun_NY = MonthAdd[month - 1] + day - 1;
	if ((!(year % 4)) && (month > 2)) Sun_NY++; //StaticDayCount记录大小月的天数 29 或30 //index 记录从哪个月開始来计算。 //flag 是用来对闰月的特殊处理。 
	//推断阳历日在春节前还是春节后 
	if (Sun_NY >= Spring_NY)
		//阳历日在春节后（含春节那天） 
	{
		Sun_NY -= Spring_NY;
		month = 1;
		index = 1;
		flag = 0;
		if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
			StaticDayCount = 29;
		else StaticDayCount = 30;
		while (Sun_NY >= StaticDayCount)
		{
			Sun_NY -= StaticDayCount;
			index++;
			if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
			{
				flag = ~flag;
				if (flag == 0) month++;
			}
			else
				month++;
			if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
				StaticDayCount = 29;
			else StaticDayCount = 30;
		}
		day = Sun_NY + 1;
	}
	else //阳历日在春节前 
	{
		Spring_NY -= Sun_NY;
		year--;
		month = 12;
		if (((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
			index = 12;
		else index = 13;
		flag = 0;
		if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
			StaticDayCount = 29;
		else StaticDayCount = 30;
		while (Spring_NY > StaticDayCount)
		{
			Spring_NY -= StaticDayCount;
			index--;
			if (flag == 0) month--;
			if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
				flag = ~flag;
			if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
				StaticDayCount = 29;
			else
				StaticDayCount = 30;
		}
		day = StaticDayCount - Spring_NY + 1;
	}
	LunarCalendarDay |= day;
	LunarCalendarDay |= (month << 6);
	if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
		return 1;
	else return 0;
}
void output(int year, int month, int day)
{
	const char* ChDay[] = { "*","初一","初二","初三","初四","初五", "初六","初七","初八","初九","初十", "十一","十二","十三","十四","十五", "十六","十七","十八","十九","二十", "廿一","廿二","廿三","廿四","廿五", "廿六","廿七","廿八","廿九","三十" };
	const char* ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","十 一","腊" };
	char str[13] = ""; strcat(str, "农历"); if (LunarCalendar(year, month, day))
	{
		strcat(str, "闰");
		strcat(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	}
	else strcat(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	strcat(str, "月"); 
	strcat(str, ChDay[LunarCalendarDay & 0x3F]);
	puts(str);
}
int days_between(Date d1, Date d2) 
{
	// 转换为tm类型
	tm tm1 = d1.to_tm();
	tm tm2 = d2.to_tm();
	// 转换为time_t类型
	time_t t1 = mktime(&tm1);
	time_t t2 = mktime(&tm2);
	// 计算时间差，转换为天数
	double diff = difftime(t2, t1);
	return fabs(diff / (24 * 60 * 60));
}
char* generateUrl(const char* key, const char* location, const char* language)
{
	sprintf(_url, "GET /v3/weather/now.json?key=%s&location=%s&language=%s&unit=c\r\n\r\n",
		key, location, language);
	cout << "查询网址为：" << endl;
	printf("GET /v3/weather/now.json?key=%s&location=%s&language=%s&unit=c\r\n\r\n",
		key, location, language);
	return _url;
}
SOCKET connetToHost(const char* host, unsigned int port)
{
	//connet to the server

	WSADATA data;
	WSAStartup(MAKEWORD(2, 2), &data);

	//1.create socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == INVALID_SOCKET)
	{
		printf("socket failed, %d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}

	//2.bind
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	//method 1, at main use truly ip
	//addr.sin_addr.S_un.S_addr = inet_addr(host);
	//method 2, use dns to get ip by name
	hostent* hostent = gethostbyname(host);
	if (hostent)
		memcpy(&addr.sin_addr, hostent->h_addr_list[0], sizeof(addr.sin_addr));
	else
	{
		printf("dns failed\n");
		return INVALID_SOCKET;
	}

	//3.connet
	//in cpp, usually return 0 is right
	if (connect(fd, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		printf("connect failed %d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	return fd;
}
string UTF8ToGB(const char* str)
{
	string result;
	// 定义一个WCHAR指针，用于存储转换后的Unicode字符串
	WCHAR* strSrc;
	char* szRes;

	//获得临时变量的大小
	//输入-1会自动计算长度
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
void parseJson(const char* jsonData)
{
	cJSON* json = cJSON_Parse(jsonData);
	if (!json)
	{
		printf("json parse failed\n");
	}
	else
	{
		cJSON* object = NULL, * item1 = NULL, * item2 = NULL, * item3 = NULL, * item4 = NULL, * item5 = NULL, * item6 = NULL, * item7 = NULL;
		cJSON* arrItem = cJSON_GetObjectItem(json, "results");
		if (arrItem)
		{
			int size = cJSON_GetArraySize(arrItem);
			if ((object = cJSON_GetArrayItem(arrItem, 0)) != NULL)
			{
				if ((item1 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item1 = cJSON_GetObjectItem(item1, "name"))
					{
						cout << "城市名："<<UTF8ToGB(item1->valuestring) << endl;
					}
				}
				if ((item2 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item2 = cJSON_GetObjectItem(item2, "country"))
					{
						cout << "所属国家："<<UTF8ToGB(item2->valuestring) << endl;
					}
				}
				if ((item3 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item3 = cJSON_GetObjectItem(item3, "timezone"))
					{
						cout << "所属时区："<<UTF8ToGB(item3->valuestring) << endl;
					}
				}
				if ((item4 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item4 = cJSON_GetObjectItem(item4, "timezone_offset"))
					{
						cout << "时差："<<UTF8ToGB(item4->valuestring) << endl;
					}
				}
				if ((item5 = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					if (item5 = cJSON_GetObjectItem(item5, "text"))
					{
						cout << "天气情况："<<UTF8ToGB(item5->valuestring) << endl;
					}
				}
				if ((item6 = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					if (item6 = cJSON_GetObjectItem(item6, "temperature"))
					{
						cout << "气温："<<UTF8ToGB(item6->valuestring) << "度" << endl;
					}
				}
				if ((item7 = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					if (item7 = cJSON_GetObjectItem(item7, "last_update"))
					{
						cout << UTF8ToGB(item7->valuestring) << endl;
					}
				}
			}

		}
	}
}
void teacherMenu(Identity*& teacher)
{
	while (1)
	{
		//调用子菜单
		teacher->openMenu();

		//将父类指针转为子类指针，调用子类的其他接口
		Teacher* tea = (Teacher*)teacher;

		//接收用户选择功能
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://个人日程
		{
			system("pause");
			system("cls");
			int flag = 1;
			while (flag)
			{
				PersonalMenu();
				int select = 0;
				cin >> select;
				switch (select)
				{
				case 1://创建个人日程
				{
					cout << "创建个人日程" << endl;
					PersonalTeachercreate(tea);
					system("pause");
					system("cls");
					break;
				}
				case 2://查看个人日程
				{
					cout << "查看个人日程" << endl;
					tea->personal.showAllPersonalSchedules();
					system("pause");
					system("cls");
					break;
				}
				case 3://查找个人日程
				{
					cout << "查找个人日程" << endl;
					PersonalTeacherfind(tea);
					system("pause");
					system("cls");
					break;
				}
				case 4://删除个人日程
				{
					cout << "删除个人日程" << endl;
					PersonalTeacheromit(tea);
					system("pause");
					system("cls");
					break;
				}
				case 5://修改个人日程
				{
					cout << "修改个人日程" << endl;
					PersonalTeachermodify(tea);
					system("pause");
					system("cls");
					break;
				}
				case 6://读取存档
				{
					string fileName = "教师工号：" + tea->m_teaId + " " + "教师姓名：" + tea->m_Name + " "+"个人日程" + ".txt";
					inputFromPersonalFile(tea->personal, fileName);
					//cout << "读取成功" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 7://保存文档
				{
					string fileName = "教师工号：" + tea->m_teaId + " " + "教师姓名：" + tea->m_Name + " " "个人日程" + ".txt";
					outputToPersonalFile(tea->personal, fileName);
					//cout << "保存成功" << endl;
					outputToPersonalFile(tea->personal, "schdule.txt");
					system("pause");
					system("cls");
					break;
				}
				case 0:
				{
					cout << "退出成功！" << endl;
					flag = 0;
					system("pause");
					system("cls");
				}
				}

			}
			break;
		}
		case 2:
		{
			system("pause");
			system("cls");
			int flag = 1;
			while (flag)
			{
				TeamMenu();
				int select = 0;
				cin >> select;
				switch (select)
				{
				case 1:
				{
					cout << "创建团队日程" << endl;
					TeamTeachercreate(tea);
					system("pause");
					system("cls");
					break;
				}
				case 2://查看团队日程
				{
					cout << "查看团队日程" << endl;
					tea->team.showAllTeamSchedules();
					system("pause");
					system("cls");
					break;
				}
				case 3://查找团队日程
				{
					cout << "查找团队日程" << endl;
					TeamTeacherfind(tea);
					system("pause");
					system("cls");
					break;
				}
				case 4://删除团队日程
				{
					cout << "删除团队日程" << endl;
					TeamTeacheromit(tea);
					system("pause");
					system("cls");
					break;
				}
				case 5://修改团队日程
				{
					cout << "修改团队日程" << endl;
					TeamTeachermodify(tea);
					system("pause");
					system("cls");
					break;
				}
				case 6://读取存档
				{
					cout << "请输入团队名：" << endl;
					string team;
					cin >> team;
					string fileName = team + "团队日程" + " " + ".txt";
					inputFromTeamFile(tea->team, fileName);
					//cout << "读取成功" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 7://保存文档
				{
					cout << "请输入团队名：" << endl;
					string team;
					cin >> team;
					string fileName = team + "团队日程" + " " + ".txt";
					outputToTeamFile(tea->team, fileName);
					system("pause");
					system("cls");
					break;
				}
				case 8://清空链表
				{
					tea->team.clearTeamSchdules();
					cout << "清除数据成功" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 0:
				{
					cout << "退出成功！" << endl;
					flag = 0;
					system("pause");
					system("cls");
				}
				}

			}
			break;
		}
		case 0://默认情况下注销登录 释放堆区数据
		{
			delete tea;//释放堆区数据 手动开辟手动释放
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		}
	}
}

void managerMenu(Identity*& manager)//传进管理员 先用父类指针传入
{
	while (1)
	{
		//调用管理员子菜单
		manager->openMenu();//利用多态 父类指针创建子类对象

		//将父类指针转为子类指针，调用子类的其他接口
		Manager* admin = (Manager*)manager;

		//接收用户选择功能
		int select = 0;
		cin >> select;

		//框架搭建 建立接口
		switch (select)
		{
		case 1://添加账号
			admin->addPerson();
			break;
		case 2://查看账号
			admin->showPerson();
			break;
		case 3://清空记录
			admin->cleanFile();
			break;
		case 4://删除指定账号
			{
				int i = 0;
				cout << "请输入操作指令，1-删除指定学生账号，2-删除指定教师账号" << endl;
				cin >> i;
				if (i == 1)
				admin->deleteStudent();
				else
				admin->deleteTeacher();
				break;
			}
		case 5://删除日程文件
			{
				int i = 0;
				cout << "请输入操作指令，1-删除学生日程文件，2-删除教师日程文件，3-删除团队日程文件" << endl;
				cin >> i;
				if (i == 1)
					admin->deleteStudentSchedule();
				else if (i == 2)
					admin->deleteTeacherSchedule();
				else if (i == 3)
					admin->deleteTeamSchedule();
				break;
			}
		case 0://默认情况下注销登录 释放堆区数据
			delete manager;//释放堆区数据 手动开辟手动释放
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void studentMenu(Identity*& student)
{
	while (1)
	{
		//调用子菜单
		student->openMenu();

		//将父类指针转为子类指针，调用子类的其他接口
		Student* stu = (Student*)student;

		//接收用户选择功能
		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1://个人日程
			{
				system("pause");
				system("cls");
				int flag = 1;
				while (flag)
				{
					PersonalMenu();
					//stu->personal.clearPersonalSchdules();
					int select = 0;
					cin >> select;
					switch (select)
					{
						case 1://创建个人日程
						{
							cout << "创建个人日程" << endl;
							PersonalStudentcreate(stu);
							system("pause");
							system("cls");
							break;
						}
						case 2://查看个人日程
						{
							cout << "查看个人日程" << endl;
							stu->personal.showAllPersonalSchedules();
							system("pause");
							system("cls");
							break;
						}
						case 3://查找个人日程
						{
							cout << "查找个人日程" << endl;
							PersonalStudentfind(stu);
							system("pause");
							system("cls");
							break;
						}
						case 4://删除个人日程
						{
							cout << "删除个人日程" << endl;
							PersonalStudentomit(stu);
							system("pause");
							system("cls");
							break;
						}
						case 5://修改个人日程
						{
							cout << "修改个人日程" << endl;
							PersonalStudentmodify(stu);
							system("pause");
							system("cls");
							break;
						}
						case 6://读取存档
						{
							string fileName = "学生学号：" + stu->m_Id + " " + "学生姓名：" + stu->m_Name  +" "+"个人日程"+".txt";
							inputFromPersonalFile(stu->personal, fileName);
							//cout << "读取成功" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 7://保存文档
						{
							string fileName = "学生学号：" + stu->m_Id + " " + "学生姓名：" + stu->m_Name + " " + "个人日程" + ".txt";
							outputToPersonalFile(stu->personal, fileName);
							//cout << "保存成功" << endl;
							outputToPersonalFile(stu->personal, "schdule.txt");
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							cout << "退出成功！" << endl;
							flag = 0;
							system("pause");
							system("cls");
						}
					}
					
				}
				break;
			}
			case 2:
			{
				system("pause");
				system("cls");
				int flag = 1;
				while (flag)
				{
					TeamMenu();
					int select = 0;
					cin >> select;
					switch (select)
					{
						case 1:
						{
							cout << "创建团队日程" << endl;
							TeamStudentcreate(stu);
							system("pause");
							system("cls");
							break;
						}
						case 2://查看团队日程
						{
							cout << "查看团队日程" << endl;
							stu->team.showAllTeamSchedules();
							system("pause");
							system("cls");
							break;
						}
						case 3://查找团队日程
						{
							cout << "查找团队日程" << endl;
							TeamStudentfind(stu);
							system("pause");
							system("cls");
							break;
						}
						case 4://删除团队日程
						{
							cout << "删除团队日程" << endl;
							TeamStudentomit(stu);
							system("pause");
							system("cls");
							break;
						}
						case 5://修改团队日程
						{
							cout << "修改团队日程" << endl;
							TeamStudentmodify(stu);
							system("pause");
							system("cls");
							break;
						}
						case 6://读取存档
						{
							cout << "请输入团队名：" << endl;
							string team;
							cin >> team;
							string fileName = team + "团队日程" + " " + ".txt";
							inputFromTeamFile(stu->team, fileName);
							//cout << "读取成功" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 7://保存文档
						{
							cout << "请输入团队名：" << endl;
							string team;
							cin >> team;
							string fileName = team + "团队日程" + " " + ".txt";
							outputToTeamFile(stu->team, fileName);
							system("pause");
							system("cls");
							break;
						}
						case 8://清空链表
						{
							stu->team.clearTeamSchdules();
							cout << "清除数据成功" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							cout << "退出成功！" << endl;
							flag = 0;
							system("pause");
							system("cls");
						}
					}
					
				}
				break;
			}
			case 0://默认情况下注销登录 释放堆区数据
			{
				delete stu;//释放堆区数据 手动开辟手动释放
				cout << "注销成功！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}
void PersonalStudentcreate(Student* s)
{
	string date,time, content;
	int priority;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "请输入日程的叙述：" << endl;
	getline(cin, content);
	cout << "请输入日程的重要性：为1~5的整数" << endl;
	cin >> priority;
	s->personal.addPersonalSchedule(new PersonalScheduleNode(date, time, content, priority));
}
void TeamStudentcreate(Student* s)
{
	string id,name,date, time, content, team;
	id = s->m_Id;
	name = s->m_Name+"（学生）";
	int priority;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "请输入日程的叙述：" << endl;
	getline(cin, content);
	cout << "请输入日程的重要性：为1~5的整数" << endl;
	cin >> priority;
	s->team.addTeamSchedule(new TeamScheduleNode(id,name,date, time, content, priority));
}
void PersonalTeachercreate(Teacher* s)
{
	string date, time, content, team;
	int priority;
	bool privacy;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "请输入日程的叙述：" << endl;
	getline(cin, content);
	cout << "请输入日程的重要性：为1~5的整数" << endl;
	cin >> priority;
	s->personal.addPersonalSchedule(new PersonalScheduleNode(date, time, content, priority));
}
void TeamTeachercreate(Teacher* s)
{
	string id, name, date, time, content, team;
	id = s->m_teaId;
	name = s->m_Name+"（导师）";
	int priority;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "请输入日程的叙述：" << endl;
	getline(cin, content);
	cout << "请输入日程的重要性：为1~5的整数" << endl;
	cin >> priority;
	s->team.addTeamSchedule(new TeamScheduleNode(id, name, date, time, content, priority));
}
void PersonalStudentfind(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->personal.queryPersonalSchedule(date, time);
}
void TeamStudentfind(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->team.queryTeamSchedule(date, time);
}
void PersonalTeacherfind(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->personal.queryPersonalSchedule(date, time);
}
void TeamTeacherfind(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->team.queryTeamSchedule(date, time);
}
void PersonalStudentomit(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->personal.deletePersonalSchedule(date, time);
}
void TeamStudentomit(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->team.deleteTeamSchedule(date, time);
}
void PersonalTeacheromit(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->personal.deletePersonalSchedule(date, time);
}
void TeamTeacheromit(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	s->team.deleteTeamSchedule(date, time);
}
void PersonalStudentmodify(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	int i;
	cout << "输入修改类型，1-修改日期，2-修改时间，3-修改叙述，4-修改重要性" << endl;
	cin >> i;
	s->personal.modifyPersonalSchedule(date, time, i);
}
void TeamStudentmodify(Student* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	int i;
	cout << "输入修改类型，1-修改日期，2-修改时间，3-修改叙述，4-修改重要性" << endl;
	cin >> i;
	s->team.modifyTeamSchedule(date, time, i);
}
void PersonalTeachermodify(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	int i;
	cout << "输入修改类型，1-修改日期，2-修改时间，3-修改叙述，4-修改重要性" << endl;
	cin >> i;
	s->personal.modifyPersonalSchedule(date, time, i);
}
void TeamTeachermodify(Teacher* s)
{
	string date, time;
	cout << "请输入日程的日期：格式为yymm-yy-mm" << endl;
	cin >> date;
	cout << "请输入日程的时间：格式为yy:mm" << endl;
	cin >> time;
	int i;
	cout << "输入修改类型，1-修改日期，2-修改时间，3-修改叙述，4-修改重要性" << endl;
	cin >> i;
	s->team.modifyTeamSchedule(date, time, i);
}
void calendarMenu()
{
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       1.查询某年某月的日历      |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       2.查询具体日期的农历      |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       3.计算日期间的天数        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       4.查询某年的属相          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       5.查询某天的星座          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       0.退出日历                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void PersonalMenu()
{
	cout << "使用前必须先读取存档，退出时必须保存文档" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.创建个人日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看个人日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查找个人日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.删除个人日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          5.修改个人日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          6.读取个人存档         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          7.保存个人文档         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.退出个人日历         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
void TeamMenu()
{
	cout << "使用前必须先读取团队日程，退出时必须保存团队日程，更换团队之前必须清除先前团队数据" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.创建团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查找团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.删除团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          5.修改团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          6.读取团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          7.保存团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          8.清除团队日程         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.退出团队日历         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
void outputToPersonalFile(PersonalScheduleList& sl, string filename)
{
	ofstream fout(filename); // 创建一个输出文件流对象，打开文件
	if (!fout) 
	{ // 如果打开失败
		cout << "打开文件失败！" << endl;
		return; // 返回
	}
	PersonalScheduleNode* p = sl.head->next; // 定义一个指针p指向日程链表的头结点的下一个结点
	while (p != NULL) 
	{ // 当p不为空时循环
		fout << p->date << " " << p->time << " " << p->content << " " << p->priority <<endl; // 将日程数据输出到文件中，用空格分隔
		p = p->next; // 更新p指向下一个结点
	}
	fout.close(); // 关闭文件
	cout << "输出成功！" << endl;
}
void outputToTeamFile(TeamScheduleList& sl, string filename)
{
	ofstream fout(filename); // 创建一个输出文件流对象，打开文件
	if (!fout)
	{ // 如果打开失败
		cout << "打开文件失败！" << endl;
		return; // 返回
	}
	TeamScheduleNode* p = sl.head->next; // 定义一个指针p指向日程链表的头结点的下一个结点
	while (p != NULL)
	{ // 当p不为空时循环
		fout <<p->id<<" "<<p->name<<" "<< p->date << " " << p->time << " " << p->content << " " << p->priority << endl; // 将日程数据输出到文件中，用空格分隔
		p = p->next; // 更新p指向下一个结点
	}
	fout.close(); // 关闭文件
	cout << "输出成功！" << endl;
}
void inputFromTeamFile(TeamScheduleList& sl, string filename)
{
	ifstream fin(filename, ios::app); // 创建一个输入文件流对象，打开文件
	if (!fin)
	{ // 如果打开失败
		cout << "打开文件失败！" << endl;
		return; // 返回
	}
	string i,n,d,t,c; // 定义字符串变量，用于存储发起人id,发起人姓名，日程日期，时间和内容
	int p; // 定义一个整数变量，用于存储重要性
	while (fin >> i >> n >> d >> t >> c>>p)
	{
		sl.addTeamSchedule(new TeamScheduleNode(i, n, d, t, c,p));
	}
	fin.close(); // 关闭文件
	cout << "读取成功！" << endl;
}
void inputFromPersonalFile(PersonalScheduleList& sl, string filename)
{
	ifstream fin(filename, ios::app); // 创建一个输入文件流对象，打开文件
	if (!fin) 
	{ // 如果打开失败
		cout << "打开文件失败！" << endl;
		return; // 返回
	}
	string d, t, c; // 定义三个字符串变量，用于存储日期，时间和内容
	int p; // 定义一个整数变量，用于存储重要性
	while (fin >> d >> t >> c >> p ) 
	{ // 当从文件中读取到四个数据时循环
		sl.addPersonalSchedule(new PersonalScheduleNode(d,t,c,p)); // 创建一个新的日程结点，并添加到日程链表中
	}
	fin.close(); // 关闭文件
	cout << "读取成功！" << endl;
}

void LoginIn(string filename, int type)
{
	Identity* person = NULL;//父类指针，指向子类对象 创建子类对象

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	//文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//接收用户信息
	string id = {};
	string name;
	string password;

	//输入身份信息
	if (type == 1)
	{
		cout << "请输入学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "\n请输入工号：";
		cin >> id;
	}

	cout << "\n请输入姓名：";
	cin >> name;

	cout << "\n请输入密码：";
	cin >> password;

	//身份验证
	if (type == 1)
	{
		//读取学生文件信息
		string fid;
		string fname;
		string fpwd;
		//读一行的信息
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//读取测试
				//cout << fid << endl;
				//cout << fname << endl;
				//cout << fpwd << endl;
				//cout << endl;

				//与用户输入的信息对比
			if (fid == id && fname == name && fpwd == password)
			{
				cout << "学生登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}

		}

	}
	else if (type == 2)
	{
		//教师身份验证
		//读取教师文件信息
		string fid;
		string fname;
		string fpwd;
		//读一行的信息
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息对比
			if (fid == id && fname == name && fpwd == password)
			{
				cout << "教师登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//进入教师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//读取管理员文件信息
		string fname;
		string fpwd;
		//读一行的信息
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息对比
			if (fname == name && fpwd == password)
			{
				cout << "管理员登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}

	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
}



int main()
{
	int select = 0;

	while (1)
	{
		cout << "======================  欢迎来到多功能日历====================="
			<< endl;
		cout << endl << "请输入您的身份或选择的功能" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学    生           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.基本日历功能       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.今日天气查找       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退出系统           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;

		switch (select)
		{
		case 1://学生
			system("pause");
			system("cls");
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师
			system("pause");
			system("cls");
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			system("pause");
			system("cls");
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		case 4:
		{
			system("pause");
			system("cls");
			int flag = 1;
			while (flag)
			{
				calendarMenu();
				int select = 0;
				cin >> select;
				switch (select)
				{
				case 1:
				{
					cout << "您正在使用日历查找功能" << endl;
					int year, month;
					cout << "请输入年份" << endl;
					cin >> year;
					cout << "请输入月份" << endl;
					cin >> month;
					Calendar a(year, month);
					a.showCalendar();
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					int i = 0;
					cout << "您正在使用公历转农历功能,输入操作指令，1为查询其他日期，0为查询当前日期" << endl;
					cin >> i;
					int year, month, day;
					if (i)
					{
						cout << "请输入年份" << endl;
						cin >> year;
						cout << "请输入月份" << endl;
						cin >> month;
						cout << "请输入日期" << endl;
						cin >> day;
						cout << "对应的农历日期为" << endl;
						output(year, month, day);
					}
					else
					{
						GetLocalTime(&sys);
						year = sys.wYear;
						month = sys.wMonth;
						day = sys.wDay;
						output(year, month, day);
					}
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					cout << "您正在使用计算日期间的天数功能" << endl
						<< "输入操作指令，0为以今天作为两个日期的其中一个，1为自己输入两个日期" << endl;
					int i = 0;
					cin >> i;
					if (i == 0)
					{
						int year, month, day;
						cout << "请输入另一个日期" << endl;
						cin >> year >> month >> day;
						Date d1(year, month, day);
						GetLocalTime(&sys);
						Date d2(sys.wYear, sys.wMonth, sys.wDay);
						cout << "两个日期相差" << days_between(d1, d2) << "天" << endl;
					}
					else
					{
						int year1, month1, day1;
						cout << "请输入第一个日期" << endl;
						cin >> year1 >> month1 >> day1;
						Date d1(year1, month1, day1);
						int year2, month2, day2;
						cout << "请输入第二个日期" << endl;
						cin >> year2 >> month2 >> day2;
						Date d2(year2, month2, day2);
						cout << "两个日期相差" << days_between(d1, d2) << "天" << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					cout << "您正在使用属相查找功能" << endl;
					int year;
					string style[12];
					style[0] = "猴";
					style[1] = "鸡";
					style[2] = "狗";
					style[3] = "猪";
					style[4] = "鼠";
					style[5] = "牛";
					style[6] = "虎";
					style[7] = "兔";
					style[8] = "龙";
					style[9] = "蛇";
					style[10] = "马";
					style[11] = "羊";
					cout << "请输入你要查找的年份" << endl;
					cin >> year;
					cout << year << "年是" << style[year % 12] << "年" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					cout << "您正在使用星座查询功能" << endl;
					int year, month, day;
					GetLocalTime(&sys);
					char f6[12][23] = { " 白羊座（3.21~4.19）  "," 金牛座（4.20~5.20）  "," 双子座（5.21~6.21）  ",
									 " 巨蟹座（6.22~7.22）  "," 狮子座（7.23~8.22）  "," 处女座（8.23~9.22）  ",
									 " 天枰座（9.23~10.23） "," 天蝎座（10.24~11.22）"," 射手座（11.23~12.21）",
									 " 摩羯座（12.22~1.19） "," 水瓶座（1.20~2.18）  "," 双鱼座（2.19~3.20）  " };
					cout << "输入操作指令：0.显示今天的星座，1.查询其它日期的星座" << endl;
					char c, f_week[7][8] = { " 星期日"," 星期一"," 星期二"," 星期三"," 星期四",
				 " 星期五"," 星期六" };;
					int k = 0, i;
					cin >> k;
					if (k == 0)
					{
						cout << "\n\n--今---天---是：" << sys.wYear << "年" << sys.wMonth << "月"
							<< sys.wDay << "日  ";
						if (sys.wDayOfWeek == 7)
						{
							cout << f_week[0] << endl;
						}
						else
						{
							cout << f_week[sys.wDayOfWeek] << endl;
						}
						int year = sys.wYear;
						int d = sys.wMonth;
						int e = sys.wDay;
						if ((d == 3 && e >= 21) || (d == 4 && e <= 19))      //判断星座
							i = 0;
						else if ((d == 4 && e >= 20) || (d == 5 && e <= 20))
							i = 1;
						else if ((d == 5 && e >= 21) || (d == 6 && e <= 21))
							i = 2;
						else if ((d == 6 && e >= 22) || (d == 7 && e <= 22))
							i = 3;
						else if ((d == 7 && e >= 23) || (d == 8 && e <= 22))
							i = 4;
						else if ((d == 8 && e >= 23) || (d == 9 && e <= 22))
							i = 5;
						else if ((d == 9 && e >= 23) || (d == 10 && e <= 23))
							i = 6;
						else if ((d == 10 && e >= 24) || (d == 11 && e <= 22))
							i = 7;
						else if ((d == 11 && e >= 23) || (d == 12 && e <= 21))
							i = 8;
						else if ((d == 12 && e >= 22) || (d == 1 && e <= 19))
							i = 9;
						else if ((d == 1 && e >= 20) || (d == 2 && e <= 18))
							i = 10;
						else
							i = 11;
						cout << "\n\n------------公元" << year << "年" << d << "月" << e << "日是";
						cout.write(f6[i], 22) << endl;
					}
					else
					{
						cout << "请输入一个日期：" << endl;
						int year, d, e;
						cin >> year >> d >> e;
						if ((d == 3 && e >= 21) || (d == 4 && e <= 19))      //判断星座
							i = 0;
						else if ((d == 4 && e >= 20) || (d == 5 && e <= 20))
							i = 1;
						else if ((d == 5 && e >= 21) || (d == 6 && e <= 21))
							i = 2;
						else if ((d == 6 && e >= 22) || (d == 7 && e <= 22))
							i = 3;
						else if ((d == 7 && e >= 23) || (d == 8 && e <= 22))
							i = 4;
						else if ((d == 8 && e >= 23) || (d == 9 && e <= 22))
							i = 5;
						else if ((d == 9 && e >= 23) || (d == 10 && e <= 23))
							i = 6;
						else if ((d == 10 && e >= 24) || (d == 11 && e <= 22))
							i = 7;
						else if ((d == 11 && e >= 23) || (d == 12 && e <= 21))
							i = 8;
						else if ((d == 12 && e >= 22) || (d == 1 && e <= 19))
							i = 9;
						else if ((d == 1 && e >= 20) || (d == 2 && e <= 18))
							i = 10;
						else
							i = 11;
						cout << "\n\n------------公元" << year << "年" << d << "月" << e << "日是";
						cout.write(f6[i], 22) << endl << endl << endl << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 0:
					cout << "退出成功！" << endl;
					flag = 0;
					system("pause");
					system("cls");

				}
			}
			break;
		}
		case 5:
		{
			system("pause");
			system("cls");
			SOCKET fd = connetToHost("116.62.81.138", 80);
			if (fd != INVALID_SOCKET)
				printf("成功连接\n");
			cout << "请输入城市名，例如：shenzhen" << endl;
			char location[30];
			cin >> location;
			char* url = generateUrl(key, location, language);
			if (send(fd, url, strlen(url), 0) <= 0)
				printf("send failed %d\n", WSAGetLastError());
			else
			{
				char buff[BUFSIZ] = { 0 };
				if (recv(fd, buff, BUFSIZ, 0) <= 0)
					printf("recv failed %d\n", WSAGetLastError());
				else
				{
					parseJson(buff);
					//save in file
					FILE* fp = fopen("weather.json", "w");
					if (!fp)
						perror("create file failed\n");
					else
						fwrite(buff, sizeof(char), strlen(buff), fp);
					fclose(fp);
				}
			}
			closesocket(fd);
			system("pause");
			system("cls");
			break;
		}
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
	