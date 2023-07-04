#include "manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Password = pwd;

	this->initVector();
}

void Manager::operMenu() {
	cout << "----------------欢迎来到机房预约系统----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       1.添加账号         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       2.查看账号         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       3.查看机房         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       4.清空预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.注销登陆         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "请输入您的选择" << endl;
}

void Manager::addPerson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;
	string filename;
	string tip;
	ofstream ofs;
	string errorTip;

	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请再次输入";
	}
	else {
		filename = TEACHER_FILE;
		tip = "请输入教职工号";
		errorTip = "教职工号重复，请再次输入";
	}
	ofs.open(filename, ios::out|ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true) {
		cin >> id;

		bool ret = this->checkRepeat(id,1);

		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	this->initVector();

	ofs.close();
	system("pause");
	system("cls");
}

void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();
	vCom.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	cout << "当前老师数量为" << vTea.size() << endl;
	ifs.close();

	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "当前机房数量为" << vCom.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id,int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}else 	if (type == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

void Manager::showPerson() {
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1) {
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), myPrint());
		system("pause");
		system("cls");
	}else if (select == 2) {
		cout << "所有学生信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), myPrint());
		system("pause");
		system("cls");
	}
}

void Manager::showComputer() {
	cout << "机房信息如下" << endl;
	for_each(vCom.begin(), vCom.end(), myPrint());
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}