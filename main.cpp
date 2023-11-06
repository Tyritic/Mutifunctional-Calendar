#pragma warning(disable:4996)��
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
//ȫ�ֺ��� ����ѧ���Ӳ˵�����
void studentMenu(Identity*& student);
void PersonalStudentcreate(Student*);
void TeamStudentcreate(Student*);
void PersonalStudentfind(Student*);
void TeamStudentfind(Student*);
void PersonalStudentomit(Student*);
void TeamStudentomit(Student*);
void PersonalStudentmodify(Student*);
void TeamStudentmodify(Student*);
//ȫ�ֺ��� �����ʦ�Ӳ˵�����
void PersonalTeachercreate(Teacher*);
void PersonalTeacherfind(Teacher*);
void PersonalTeacheromit(Teacher*);
void PersonalTeachermodify(Teacher*);
void TeamTeachercreate(Teacher*);
void TeamTeacherfind(Teacher*);
void TeamTeacheromit(Teacher*);
void TeamTeachermodify(Teacher*);
void calendarMenu();//�����˵�
//��ݲ˵�
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);
void managerMenu(Identity*& manager);
//�����ճ̲˵��������ճ̲˵�
void PersonalMenu();
void TeamMenu();
int LunarCalendar(int year, int month, int day);
//���������ݱ��浽�����ļ���
void outputToPersonalFile(PersonalScheduleList& sl, string filename);
//���������ݱ��浽�Ŷ��ļ���
void outputToTeamFile(TeamScheduleList& sl, string filename);
//���Ŷ��ļ��ж�ȡ��������
void inputFromTeamFile(TeamScheduleList& sl, string filename);
//�Ӹ����ļ��ж�ȡ��������
void inputFromPersonalFile(PersonalScheduleList& sl, string filename);
const char* host = "api.seniverse.com";
const char* key = "SmKNAkNDNgy0VQHrh";
const char* language = "zh-Hans";
char _url[100] = { 0 };
SYSTEMTIME sys;      //ϵͳʱ�����

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
	//Spring_NY ��¼�����뵱��Ԫ����������
	if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
		Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
	else Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
	Sun_NY = MonthAdd[month - 1] + day - 1;
	if ((!(year % 4)) && (month > 2)) Sun_NY++; //StaticDayCount��¼��С�µ����� 29 ��30 //index ��¼���ĸ����_ʼ�����㡣 //flag �����������µ����⴦�� 
	//�ƶ��������ڴ���ǰ���Ǵ��ں� 
	if (Sun_NY >= Spring_NY)
		//�������ڴ��ں󣨺��������죩 
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
	else //�������ڴ���ǰ 
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
	const char* ChDay[] = { "*","��һ","����","����","����","����", "����","����","����","����","��ʮ", "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��", "ʮ��","ʮ��","ʮ��","ʮ��","��ʮ", "إһ","إ��","إ��","إ��","إ��", "إ��","إ��","إ��","إ��","��ʮ" };
	const char* ChMonth[] = { "*","��","��","��","��","��","��","��","��","��","ʮ","ʮ һ","��" };
	char str[13] = ""; strcat(str, "ũ��"); if (LunarCalendar(year, month, day))
	{
		strcat(str, "��");
		strcat(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	}
	else strcat(str, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	strcat(str, "��"); 
	strcat(str, ChDay[LunarCalendarDay & 0x3F]);
	puts(str);
}
int days_between(Date d1, Date d2) 
{
	// ת��Ϊtm����
	tm tm1 = d1.to_tm();
	tm tm2 = d2.to_tm();
	// ת��Ϊtime_t����
	time_t t1 = mktime(&tm1);
	time_t t2 = mktime(&tm2);
	// ����ʱ��ת��Ϊ����
	double diff = difftime(t2, t1);
	return fabs(diff / (24 * 60 * 60));
}
char* generateUrl(const char* key, const char* location, const char* language)
{
	sprintf(_url, "GET /v3/weather/now.json?key=%s&location=%s&language=%s&unit=c\r\n\r\n",
		key, location, language);
	cout << "��ѯ��ַΪ��" << endl;
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
	// ����һ��WCHARָ�룬���ڴ洢ת�����Unicode�ַ���
	WCHAR* strSrc;
	char* szRes;

	//�����ʱ�����Ĵ�С
	//����-1���Զ����㳤��
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
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
						cout << "��������"<<UTF8ToGB(item1->valuestring) << endl;
					}
				}
				if ((item2 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item2 = cJSON_GetObjectItem(item2, "country"))
					{
						cout << "�������ң�"<<UTF8ToGB(item2->valuestring) << endl;
					}
				}
				if ((item3 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item3 = cJSON_GetObjectItem(item3, "timezone"))
					{
						cout << "����ʱ����"<<UTF8ToGB(item3->valuestring) << endl;
					}
				}
				if ((item4 = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					if (item4 = cJSON_GetObjectItem(item4, "timezone_offset"))
					{
						cout << "ʱ�"<<UTF8ToGB(item4->valuestring) << endl;
					}
				}
				if ((item5 = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					if (item5 = cJSON_GetObjectItem(item5, "text"))
					{
						cout << "���������"<<UTF8ToGB(item5->valuestring) << endl;
					}
				}
				if ((item6 = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					if (item6 = cJSON_GetObjectItem(item6, "temperature"))
					{
						cout << "���£�"<<UTF8ToGB(item6->valuestring) << "��" << endl;
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
		//�����Ӳ˵�
		teacher->openMenu();

		//������ָ��תΪ����ָ�룬��������������ӿ�
		Teacher* tea = (Teacher*)teacher;

		//�����û�ѡ����
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://�����ճ�
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
				case 1://���������ճ�
				{
					cout << "���������ճ�" << endl;
					PersonalTeachercreate(tea);
					system("pause");
					system("cls");
					break;
				}
				case 2://�鿴�����ճ�
				{
					cout << "�鿴�����ճ�" << endl;
					tea->personal.showAllPersonalSchedules();
					system("pause");
					system("cls");
					break;
				}
				case 3://���Ҹ����ճ�
				{
					cout << "���Ҹ����ճ�" << endl;
					PersonalTeacherfind(tea);
					system("pause");
					system("cls");
					break;
				}
				case 4://ɾ�������ճ�
				{
					cout << "ɾ�������ճ�" << endl;
					PersonalTeacheromit(tea);
					system("pause");
					system("cls");
					break;
				}
				case 5://�޸ĸ����ճ�
				{
					cout << "�޸ĸ����ճ�" << endl;
					PersonalTeachermodify(tea);
					system("pause");
					system("cls");
					break;
				}
				case 6://��ȡ�浵
				{
					string fileName = "��ʦ���ţ�" + tea->m_teaId + " " + "��ʦ������" + tea->m_Name + " "+"�����ճ�" + ".txt";
					inputFromPersonalFile(tea->personal, fileName);
					//cout << "��ȡ�ɹ�" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 7://�����ĵ�
				{
					string fileName = "��ʦ���ţ�" + tea->m_teaId + " " + "��ʦ������" + tea->m_Name + " " "�����ճ�" + ".txt";
					outputToPersonalFile(tea->personal, fileName);
					//cout << "����ɹ�" << endl;
					outputToPersonalFile(tea->personal, "schdule.txt");
					system("pause");
					system("cls");
					break;
				}
				case 0:
				{
					cout << "�˳��ɹ���" << endl;
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
					cout << "�����Ŷ��ճ�" << endl;
					TeamTeachercreate(tea);
					system("pause");
					system("cls");
					break;
				}
				case 2://�鿴�Ŷ��ճ�
				{
					cout << "�鿴�Ŷ��ճ�" << endl;
					tea->team.showAllTeamSchedules();
					system("pause");
					system("cls");
					break;
				}
				case 3://�����Ŷ��ճ�
				{
					cout << "�����Ŷ��ճ�" << endl;
					TeamTeacherfind(tea);
					system("pause");
					system("cls");
					break;
				}
				case 4://ɾ���Ŷ��ճ�
				{
					cout << "ɾ���Ŷ��ճ�" << endl;
					TeamTeacheromit(tea);
					system("pause");
					system("cls");
					break;
				}
				case 5://�޸��Ŷ��ճ�
				{
					cout << "�޸��Ŷ��ճ�" << endl;
					TeamTeachermodify(tea);
					system("pause");
					system("cls");
					break;
				}
				case 6://��ȡ�浵
				{
					cout << "�������Ŷ�����" << endl;
					string team;
					cin >> team;
					string fileName = team + "�Ŷ��ճ�" + " " + ".txt";
					inputFromTeamFile(tea->team, fileName);
					//cout << "��ȡ�ɹ�" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 7://�����ĵ�
				{
					cout << "�������Ŷ�����" << endl;
					string team;
					cin >> team;
					string fileName = team + "�Ŷ��ճ�" + " " + ".txt";
					outputToTeamFile(tea->team, fileName);
					system("pause");
					system("cls");
					break;
				}
				case 8://�������
				{
					tea->team.clearTeamSchdules();
					cout << "������ݳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 0:
				{
					cout << "�˳��ɹ���" << endl;
					flag = 0;
					system("pause");
					system("cls");
				}
				}

			}
			break;
		}
		case 0://Ĭ�������ע����¼ �ͷŶ�������
		{
			delete tea;//�ͷŶ������� �ֶ������ֶ��ͷ�
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		}
	}
}

void managerMenu(Identity*& manager)//��������Ա ���ø���ָ�봫��
{
	while (1)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();//���ö�̬ ����ָ�봴���������

		//������ָ��תΪ����ָ�룬��������������ӿ�
		Manager* admin = (Manager*)manager;

		//�����û�ѡ����
		int select = 0;
		cin >> select;

		//��ܴ �����ӿ�
		switch (select)
		{
		case 1://����˺�
			admin->addPerson();
			break;
		case 2://�鿴�˺�
			admin->showPerson();
			break;
		case 3://��ռ�¼
			admin->cleanFile();
			break;
		case 4://ɾ��ָ���˺�
			{
				int i = 0;
				cout << "���������ָ�1-ɾ��ָ��ѧ���˺ţ�2-ɾ��ָ����ʦ�˺�" << endl;
				cin >> i;
				if (i == 1)
				admin->deleteStudent();
				else
				admin->deleteTeacher();
				break;
			}
		case 5://ɾ���ճ��ļ�
			{
				int i = 0;
				cout << "���������ָ�1-ɾ��ѧ���ճ��ļ���2-ɾ����ʦ�ճ��ļ���3-ɾ���Ŷ��ճ��ļ�" << endl;
				cin >> i;
				if (i == 1)
					admin->deleteStudentSchedule();
				else if (i == 2)
					admin->deleteTeacherSchedule();
				else if (i == 3)
					admin->deleteTeamSchedule();
				break;
			}
		case 0://Ĭ�������ע����¼ �ͷŶ�������
			delete manager;//�ͷŶ������� �ֶ������ֶ��ͷ�
			cout << "ע���ɹ���" << endl;
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
		//�����Ӳ˵�
		student->openMenu();

		//������ָ��תΪ����ָ�룬��������������ӿ�
		Student* stu = (Student*)student;

		//�����û�ѡ����
		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1://�����ճ�
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
						case 1://���������ճ�
						{
							cout << "���������ճ�" << endl;
							PersonalStudentcreate(stu);
							system("pause");
							system("cls");
							break;
						}
						case 2://�鿴�����ճ�
						{
							cout << "�鿴�����ճ�" << endl;
							stu->personal.showAllPersonalSchedules();
							system("pause");
							system("cls");
							break;
						}
						case 3://���Ҹ����ճ�
						{
							cout << "���Ҹ����ճ�" << endl;
							PersonalStudentfind(stu);
							system("pause");
							system("cls");
							break;
						}
						case 4://ɾ�������ճ�
						{
							cout << "ɾ�������ճ�" << endl;
							PersonalStudentomit(stu);
							system("pause");
							system("cls");
							break;
						}
						case 5://�޸ĸ����ճ�
						{
							cout << "�޸ĸ����ճ�" << endl;
							PersonalStudentmodify(stu);
							system("pause");
							system("cls");
							break;
						}
						case 6://��ȡ�浵
						{
							string fileName = "ѧ��ѧ�ţ�" + stu->m_Id + " " + "ѧ��������" + stu->m_Name  +" "+"�����ճ�"+".txt";
							inputFromPersonalFile(stu->personal, fileName);
							//cout << "��ȡ�ɹ�" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 7://�����ĵ�
						{
							string fileName = "ѧ��ѧ�ţ�" + stu->m_Id + " " + "ѧ��������" + stu->m_Name + " " + "�����ճ�" + ".txt";
							outputToPersonalFile(stu->personal, fileName);
							//cout << "����ɹ�" << endl;
							outputToPersonalFile(stu->personal, "schdule.txt");
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							cout << "�˳��ɹ���" << endl;
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
							cout << "�����Ŷ��ճ�" << endl;
							TeamStudentcreate(stu);
							system("pause");
							system("cls");
							break;
						}
						case 2://�鿴�Ŷ��ճ�
						{
							cout << "�鿴�Ŷ��ճ�" << endl;
							stu->team.showAllTeamSchedules();
							system("pause");
							system("cls");
							break;
						}
						case 3://�����Ŷ��ճ�
						{
							cout << "�����Ŷ��ճ�" << endl;
							TeamStudentfind(stu);
							system("pause");
							system("cls");
							break;
						}
						case 4://ɾ���Ŷ��ճ�
						{
							cout << "ɾ���Ŷ��ճ�" << endl;
							TeamStudentomit(stu);
							system("pause");
							system("cls");
							break;
						}
						case 5://�޸��Ŷ��ճ�
						{
							cout << "�޸��Ŷ��ճ�" << endl;
							TeamStudentmodify(stu);
							system("pause");
							system("cls");
							break;
						}
						case 6://��ȡ�浵
						{
							cout << "�������Ŷ�����" << endl;
							string team;
							cin >> team;
							string fileName = team + "�Ŷ��ճ�" + " " + ".txt";
							inputFromTeamFile(stu->team, fileName);
							//cout << "��ȡ�ɹ�" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 7://�����ĵ�
						{
							cout << "�������Ŷ�����" << endl;
							string team;
							cin >> team;
							string fileName = team + "�Ŷ��ճ�" + " " + ".txt";
							outputToTeamFile(stu->team, fileName);
							system("pause");
							system("cls");
							break;
						}
						case 8://�������
						{
							stu->team.clearTeamSchdules();
							cout << "������ݳɹ�" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 0:
						{
							cout << "�˳��ɹ���" << endl;
							flag = 0;
							system("pause");
							system("cls");
						}
					}
					
				}
				break;
			}
			case 0://Ĭ�������ע����¼ �ͷŶ�������
			{
				delete stu;//�ͷŶ������� �ֶ������ֶ��ͷ�
				cout << "ע���ɹ���" << endl;
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
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "�������ճ̵�������" << endl;
	getline(cin, content);
	cout << "�������ճ̵���Ҫ�ԣ�Ϊ1~5������" << endl;
	cin >> priority;
	s->personal.addPersonalSchedule(new PersonalScheduleNode(date, time, content, priority));
}
void TeamStudentcreate(Student* s)
{
	string id,name,date, time, content, team;
	id = s->m_Id;
	name = s->m_Name+"��ѧ����";
	int priority;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "�������ճ̵�������" << endl;
	getline(cin, content);
	cout << "�������ճ̵���Ҫ�ԣ�Ϊ1~5������" << endl;
	cin >> priority;
	s->team.addTeamSchedule(new TeamScheduleNode(id,name,date, time, content, priority));
}
void PersonalTeachercreate(Teacher* s)
{
	string date, time, content, team;
	int priority;
	bool privacy;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "�������ճ̵�������" << endl;
	getline(cin, content);
	cout << "�������ճ̵���Ҫ�ԣ�Ϊ1~5������" << endl;
	cin >> priority;
	s->personal.addPersonalSchedule(new PersonalScheduleNode(date, time, content, priority));
}
void TeamTeachercreate(Teacher* s)
{
	string id, name, date, time, content, team;
	id = s->m_teaId;
	name = s->m_Name+"����ʦ��";
	int priority;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	cin.ignore();
	cout << "�������ճ̵�������" << endl;
	getline(cin, content);
	cout << "�������ճ̵���Ҫ�ԣ�Ϊ1~5������" << endl;
	cin >> priority;
	s->team.addTeamSchedule(new TeamScheduleNode(id, name, date, time, content, priority));
}
void PersonalStudentfind(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->personal.queryPersonalSchedule(date, time);
}
void TeamStudentfind(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->team.queryTeamSchedule(date, time);
}
void PersonalTeacherfind(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->personal.queryPersonalSchedule(date, time);
}
void TeamTeacherfind(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->team.queryTeamSchedule(date, time);
}
void PersonalStudentomit(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->personal.deletePersonalSchedule(date, time);
}
void TeamStudentomit(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->team.deleteTeamSchedule(date, time);
}
void PersonalTeacheromit(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->personal.deletePersonalSchedule(date, time);
}
void TeamTeacheromit(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	s->team.deleteTeamSchedule(date, time);
}
void PersonalStudentmodify(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	int i;
	cout << "�����޸����ͣ�1-�޸����ڣ�2-�޸�ʱ�䣬3-�޸�������4-�޸���Ҫ��" << endl;
	cin >> i;
	s->personal.modifyPersonalSchedule(date, time, i);
}
void TeamStudentmodify(Student* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	int i;
	cout << "�����޸����ͣ�1-�޸����ڣ�2-�޸�ʱ�䣬3-�޸�������4-�޸���Ҫ��" << endl;
	cin >> i;
	s->team.modifyTeamSchedule(date, time, i);
}
void PersonalTeachermodify(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	int i;
	cout << "�����޸����ͣ�1-�޸����ڣ�2-�޸�ʱ�䣬3-�޸�������4-�޸���Ҫ��" << endl;
	cin >> i;
	s->personal.modifyPersonalSchedule(date, time, i);
}
void TeamTeachermodify(Teacher* s)
{
	string date, time;
	cout << "�������ճ̵����ڣ���ʽΪyymm-yy-mm" << endl;
	cin >> date;
	cout << "�������ճ̵�ʱ�䣺��ʽΪyy:mm" << endl;
	cin >> time;
	int i;
	cout << "�����޸����ͣ�1-�޸����ڣ�2-�޸�ʱ�䣬3-�޸�������4-�޸���Ҫ��" << endl;
	cin >> i;
	s->team.modifyTeamSchedule(date, time, i);
}
void calendarMenu()
{
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       1.��ѯĳ��ĳ�µ�����      |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       2.��ѯ�������ڵ�ũ��      |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       3.�������ڼ������        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       4.��ѯĳ�������          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       5.��ѯĳ�������          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|       0.�˳�����                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void PersonalMenu()
{
	cout << "ʹ��ǰ�����ȶ�ȡ�浵���˳�ʱ���뱣���ĵ�" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.���������ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�����ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.���Ҹ����ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ɾ�������ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          5.�޸ĸ����ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          6.��ȡ���˴浵         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          7.��������ĵ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.�˳���������         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
void TeamMenu()
{
	cout << "ʹ��ǰ�����ȶ�ȡ�Ŷ��ճ̣��˳�ʱ���뱣���Ŷ��ճ̣������Ŷ�֮ǰ���������ǰ�Ŷ�����" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.�����Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�����Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ɾ���Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          5.�޸��Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          6.��ȡ�Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          7.�����Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          8.����Ŷ��ճ�         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.�˳��Ŷ�����         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
void outputToPersonalFile(PersonalScheduleList& sl, string filename)
{
	ofstream fout(filename); // ����һ������ļ������󣬴��ļ�
	if (!fout) 
	{ // �����ʧ��
		cout << "���ļ�ʧ�ܣ�" << endl;
		return; // ����
	}
	PersonalScheduleNode* p = sl.head->next; // ����һ��ָ��pָ���ճ������ͷ������һ�����
	while (p != NULL) 
	{ // ��p��Ϊ��ʱѭ��
		fout << p->date << " " << p->time << " " << p->content << " " << p->priority <<endl; // ���ճ�����������ļ��У��ÿո�ָ�
		p = p->next; // ����pָ����һ�����
	}
	fout.close(); // �ر��ļ�
	cout << "����ɹ���" << endl;
}
void outputToTeamFile(TeamScheduleList& sl, string filename)
{
	ofstream fout(filename); // ����һ������ļ������󣬴��ļ�
	if (!fout)
	{ // �����ʧ��
		cout << "���ļ�ʧ�ܣ�" << endl;
		return; // ����
	}
	TeamScheduleNode* p = sl.head->next; // ����һ��ָ��pָ���ճ������ͷ������һ�����
	while (p != NULL)
	{ // ��p��Ϊ��ʱѭ��
		fout <<p->id<<" "<<p->name<<" "<< p->date << " " << p->time << " " << p->content << " " << p->priority << endl; // ���ճ�����������ļ��У��ÿո�ָ�
		p = p->next; // ����pָ����һ�����
	}
	fout.close(); // �ر��ļ�
	cout << "����ɹ���" << endl;
}
void inputFromTeamFile(TeamScheduleList& sl, string filename)
{
	ifstream fin(filename, ios::app); // ����һ�������ļ������󣬴��ļ�
	if (!fin)
	{ // �����ʧ��
		cout << "���ļ�ʧ�ܣ�" << endl;
		return; // ����
	}
	string i,n,d,t,c; // �����ַ������������ڴ洢������id,�������������ճ����ڣ�ʱ�������
	int p; // ����һ���������������ڴ洢��Ҫ��
	while (fin >> i >> n >> d >> t >> c>>p)
	{
		sl.addTeamSchedule(new TeamScheduleNode(i, n, d, t, c,p));
	}
	fin.close(); // �ر��ļ�
	cout << "��ȡ�ɹ���" << endl;
}
void inputFromPersonalFile(PersonalScheduleList& sl, string filename)
{
	ifstream fin(filename, ios::app); // ����һ�������ļ������󣬴��ļ�
	if (!fin) 
	{ // �����ʧ��
		cout << "���ļ�ʧ�ܣ�" << endl;
		return; // ����
	}
	string d, t, c; // ���������ַ������������ڴ洢���ڣ�ʱ�������
	int p; // ����һ���������������ڴ洢��Ҫ��
	while (fin >> d >> t >> c >> p ) 
	{ // �����ļ��ж�ȡ���ĸ�����ʱѭ��
		sl.addPersonalSchedule(new PersonalScheduleNode(d,t,c,p)); // ����һ���µ��ճ̽�㣬����ӵ��ճ�������
	}
	fin.close(); // �ر��ļ�
	cout << "��ȡ�ɹ���" << endl;
}

void LoginIn(string filename, int type)
{
	Identity* person = NULL;//����ָ�룬ָ��������� �����������

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//�����û���Ϣ
	string id = {};
	string name;
	string password;

	//���������Ϣ
	if (type == 1)
	{
		cout << "������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "\n�����빤�ţ�";
		cin >> id;
	}

	cout << "\n������������";
	cin >> name;

	cout << "\n���������룺";
	cin >> password;

	//�����֤
	if (type == 1)
	{
		//��ȡѧ���ļ���Ϣ
		string fid;
		string fname;
		string fpwd;
		//��һ�е���Ϣ
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//��ȡ����
				//cout << fid << endl;
				//cout << fname << endl;
				//cout << fpwd << endl;
				//cout << endl;

				//���û��������Ϣ�Ա�
			if (fid == id && fname == name && fpwd == password)
			{
				cout << "ѧ����¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}

		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		//��ȡ��ʦ�ļ���Ϣ
		string fid;
		string fname;
		string fpwd;
		//��һ�е���Ϣ
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ�Ա�
			if (fid == id && fname == name && fpwd == password)
			{
				cout << "��ʦ��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//�����ʦ����Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//��ȡ����Ա�ļ���Ϣ
		string fname;
		string fpwd;
		//��һ�е���Ϣ
		while (ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ�Ա�
			if (fname == name && fpwd == password)
			{
				cout << "����Ա��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}

	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}



int main()
{
	int select = 0;

	while (1)
	{
		cout << "======================  ��ӭ�����๦������====================="
			<< endl;
		cout << endl << "������������ݻ�ѡ��Ĺ���" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.������������       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.������������       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.�˳�ϵͳ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;

		switch (select)
		{
		case 1://ѧ��
			system("pause");
			system("cls");
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			system("pause");
			system("cls");
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			system("pause");
			system("cls");
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ��һ��ʹ��" << endl;
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
					cout << "������ʹ���������ҹ���" << endl;
					int year, month;
					cout << "���������" << endl;
					cin >> year;
					cout << "�������·�" << endl;
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
					cout << "������ʹ�ù���תũ������,�������ָ�1Ϊ��ѯ�������ڣ�0Ϊ��ѯ��ǰ����" << endl;
					cin >> i;
					int year, month, day;
					if (i)
					{
						cout << "���������" << endl;
						cin >> year;
						cout << "�������·�" << endl;
						cin >> month;
						cout << "����������" << endl;
						cin >> day;
						cout << "��Ӧ��ũ������Ϊ" << endl;
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
					cout << "������ʹ�ü������ڼ����������" << endl
						<< "�������ָ�0Ϊ�Խ�����Ϊ�������ڵ�����һ����1Ϊ�Լ�������������" << endl;
					int i = 0;
					cin >> i;
					if (i == 0)
					{
						int year, month, day;
						cout << "��������һ������" << endl;
						cin >> year >> month >> day;
						Date d1(year, month, day);
						GetLocalTime(&sys);
						Date d2(sys.wYear, sys.wMonth, sys.wDay);
						cout << "�����������" << days_between(d1, d2) << "��" << endl;
					}
					else
					{
						int year1, month1, day1;
						cout << "�������һ������" << endl;
						cin >> year1 >> month1 >> day1;
						Date d1(year1, month1, day1);
						int year2, month2, day2;
						cout << "������ڶ�������" << endl;
						cin >> year2 >> month2 >> day2;
						Date d2(year2, month2, day2);
						cout << "�����������" << days_between(d1, d2) << "��" << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					cout << "������ʹ��������ҹ���" << endl;
					int year;
					string style[12];
					style[0] = "��";
					style[1] = "��";
					style[2] = "��";
					style[3] = "��";
					style[4] = "��";
					style[5] = "ţ";
					style[6] = "��";
					style[7] = "��";
					style[8] = "��";
					style[9] = "��";
					style[10] = "��";
					style[11] = "��";
					cout << "��������Ҫ���ҵ����" << endl;
					cin >> year;
					cout << year << "����" << style[year % 12] << "��" << endl;
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					cout << "������ʹ��������ѯ����" << endl;
					int year, month, day;
					GetLocalTime(&sys);
					char f6[12][23] = { " ��������3.21~4.19��  "," ��ţ����4.20~5.20��  "," ˫������5.21~6.21��  ",
									 " ��з����6.22~7.22��  "," ʨ������7.23~8.22��  "," ��Ů����8.23~9.22��  ",
									 " ��������9.23~10.23�� "," ��Ы����10.24~11.22��"," ��������11.23~12.21��",
									 " Ħ������12.22~1.19�� "," ˮƿ����1.20~2.18��  "," ˫������2.19~3.20��  " };
					cout << "�������ָ�0.��ʾ�����������1.��ѯ�������ڵ�����" << endl;
					char c, f_week[7][8] = { " ������"," ����һ"," ���ڶ�"," ������"," ������",
				 " ������"," ������" };;
					int k = 0, i;
					cin >> k;
					if (k == 0)
					{
						cout << "\n\n--��---��---�ǣ�" << sys.wYear << "��" << sys.wMonth << "��"
							<< sys.wDay << "��  ";
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
						if ((d == 3 && e >= 21) || (d == 4 && e <= 19))      //�ж�����
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
						cout << "\n\n------------��Ԫ" << year << "��" << d << "��" << e << "����";
						cout.write(f6[i], 22) << endl;
					}
					else
					{
						cout << "������һ�����ڣ�" << endl;
						int year, d, e;
						cin >> year >> d >> e;
						if ((d == 3 && e >= 21) || (d == 4 && e <= 19))      //�ж�����
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
						cout << "\n\n------------��Ԫ" << year << "��" << d << "��" << e << "����";
						cout.write(f6[i], 22) << endl << endl << endl << endl;
					}
					system("pause");
					system("cls");
					break;
				}
				case 0:
					cout << "�˳��ɹ���" << endl;
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
				printf("�ɹ�����\n");
			cout << "����������������磺shenzhen" << endl;
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
			cout << "���������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
	