#include "manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Password = pwd;
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

	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "请输入学号";
	}
	else {
		filename = TEACHER_FILE;
		tip = "请输入教职工号";

	}
	ofs.open(filename, ios::out|ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Manager::showPerson() {}

void Manager::showComputer() {}

void Manager::cleanFile() {}