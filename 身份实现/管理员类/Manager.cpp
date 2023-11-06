#include "Manager.h"
//有参构造(管理员姓名，密码)
Manager::Manager(string name, string password)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = password;
}
//全局函数 进入管理员子菜单界面

//选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	initVector();//调用初始化容器接口，重新获取文件中的数据 及时更新数据
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.清空账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.删除指定账号        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.删除日程文件        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson()
{
	//提示用户 添加身份类型
	cout << "请输入添加账号类型" << endl;
	cout << "1——添加学生" << endl;
	cout << "2——添加教师" << endl;

	string filename;//操作的文件名 id
	string tip;//提示用户输入的id
	string errortip;//id重复提示
	ofstream ofs;//文件操作对象

	//接受用户选择身份类型
	int select = 0;
	cin >> select;

	if (select == 1)//添加学生
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入";
	}
	else//添加教师
	{
		filename = TEACHER_FILE;
		tip = "请输入工号：";
		errortip = "工号重复，请重新输入";
	}

	//利用追加的方式写文件
	ofs.open(filename, ios::app);

	//接收用户添加信息
	string id;
	string name;
	string pwd;

	cout << tip;
	//对输入的学号进行重复判断
	while (1)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;

	//向文件添加数据 空格分割
	ofs <<id << " " << name << " " << pwd << " "<<endl ;
	cout << "添加成功！" << endl;

	ofs.close();
	system("pause");
	system("cls");

	//调用初始化容器接口，重新获取文件中的数据 及时更新数据
	//this->initVector();
}


//初始化容器
void Manager::initVector()
{
	//学生 教师容器 清空
	vStu.clear();
	vTea.clear();

	//读取信息 学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	//文件打开判断
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	//创建学生对象
	Student s;

	//读取学生信息并放入vStu中
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();
	cout << "当前学生数量为：" << vStu.size() << endl;//测试
	
	//读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_teaId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
	cout << "当前教师数量为：" << vTea.size() << endl;
	

}

void Manager::showPerson()
{
	cout << "请输入查看内容" << endl;
	cout << "1——查看所有学生账号" << endl;
	cout << "2——查看所有教师账号" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		
		cout << "所有学生信息如下：" << endl;
		for (auto Stu : vStu)
		{
			cout << "学生学号：" << Stu.m_Id <<" " << "学生姓名：" << Stu.m_Name <<" " << "学生密码：" << Stu.m_Pwd << endl;
		}
	}
	else
	{
		
		cout << "所有教师信息如下：" << endl;
		for (auto Tea  : vTea)
		{
			cout << "教师工号：" << Tea.m_teaId << " " << "教师姓名：" << Tea.m_Name << " " << "教师密码：" << Tea.m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测重复 参数1 检测学号/工号 参数2 检测身份类型
bool Manager::checkRepeat(string id, int type)
{
	//检测类型 有重复提示
	if (type == 1)
	{
		//检测学生学号
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测教师工号
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_teaId)
			{
				return true;
			}
		}
	}
	//默认没有重复 
	return false;
}

void Manager::cleanFile()
{
	int i;
	cout << "输入操作指令" << endl;
	cout << "1——清空所有学生账号" << endl;
	cout << "2——清空所有教师账号" << endl;
	cin >> i;
	if (i == 1)
	{
		ofstream ofs(STUDENT_FILE, ios::trunc);
		ofs.close();
		cout << "清空所有学生记录！" << endl;
		//vStu.clear();
		initVector();
		system("pause");
		system("cls");
	}
	else
	{
		ofstream ofs(TEACHER_FILE, ios::trunc);
		ofs.close();
		cout << "清空所有教师记录！" << endl;
		//vTea.clear();
		initVector();
		system("pause");
		system("cls");
	}
}

void Manager::deleteStudentSchedule()
{
	string id;
	string name;
	cout << "输入学生学号："<<endl;
	cin >> id;
	cout << "输入学生姓名：" << endl;
	cin >> name;
	string Path = "学生学号：" + id + " " + "学生姓名：" + name + " " + "个人日程" + ".txt";
	if (remove(Path.c_str())==0)
	{
		cout << "删除日程文件成功" << endl;
	}
	else
	{
		cout << "删除日程文件失败，可能文件不存在" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeacherSchedule()
{
	string id;
	string name;
	cout << "输入教师工号：" << endl;
	cin >> id;
	cout << "输入教师姓名：" << endl;
	cin >> name;
	string Path = "教师工号：" + id + " " + "教师姓名：" + name + " " + "个人日程" + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "删除日程文件成功" << endl;
	}
	else
	{
		cout << "删除日程文件失败，可能文件不存在" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeamSchedule()
{
	string team;
	cout << "请输入团队名称：" << endl;
	cin >> team;
	string Path = team + "团队日程" + " " + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "删除日程文件成功" << endl;
	}
	else
	{
		cout << "删除日程文件失败，可能文件不存在" << endl;
	}
	system("pause");
	system("cls");

}

void Manager::deleteStudent()
{
	string id,name;
	cout << "请输入学生学号：" << endl;
	cin >> id;
	cout << "请输入学生姓名：" << endl;
	cin >> name;
	Student stu;
	stringstream stream1(id);
	stringstream stream2(name);
	stream1 >> stu.m_Id;
	stream2 >> stu.m_Name;
	static std::vector<Student>::iterator delIt = vStu.end();
	delIt = std::find(vStu.begin(), vStu.end(), stu);//查找日程对象
	if (delIt != vStu.end())
	{
		vStu.erase(delIt);//删除对象
		delIt = vStu.end();
		fstream write(STUDENT_FILE, ios::trunc | ios::out);//以打开文件并把文件内容覆盖清空，如果文件不存在则创建文件
		if (!write.is_open())
		{
			cerr << STUDENT_FILE<< " 操作失败";
			return;
		}
		for (auto& stu : vStu)
		{
			string info = stu.formatInfo();//保存格式化后的字符串
			write.write(info.c_str(), info.size());//写入文件
		}
		write.close();
	}
	string Path = "学生学号：" + id + " " + "学生姓名：" + name + " " + "个人日程" + ".txt";;
	if (remove(Path.c_str()) == 0)
	{
		cout << "删除日程文件成功" << endl;
	}
	else
	{
		cout << "删除日程文件失败，可能文件不存在" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeacher()
{
	string id, name;
	cout << "请输入教师工号：" << endl;
	cin >> id;
	cout << "请输入教师姓名：" << endl;
	cin >> name;
	Teacher tea;
	stringstream stream1(id);
	stringstream stream2(name);
	stream1 >> tea.m_teaId;
	stream2 >> tea.m_Name;
	static std::vector<Teacher>::iterator delIt = vTea.end();
	delIt = std::find(vTea.begin(), vTea.end(), tea);//查找教师对象
	if (delIt != vTea.end())
	{
		vTea.erase(delIt);//删除对象
		delIt = vTea.end();
		fstream write(TEACHER_FILE, ios::trunc | ios::out);//以打开文件并把文件内容覆盖清空，如果文件不存在则创建文件
		if (!write.is_open())
		{
			cerr << TEACHER_FILE << " 操作失败";
			return;
		}
		for (auto& tea : vTea)
		{
			string info = tea.formatInfo();//保存格式化后的字符串
			write.write(info.c_str(), info.size());//写入文件
		}
		write.close();
	}
	string Path = "教师工号：" + id + " " + "教师姓名：" + name + " " + "个人日程" + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "删除日程文件成功" << endl;
	}
	else
	{
		cout << "删除日程文件失败，可能文件不存在" << endl;
	}
	system("pause");
	system("cls");
}




