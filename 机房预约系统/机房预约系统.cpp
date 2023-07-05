/*机房预约系统
*1.1系统简介
* 学校现有几个不同规格的机房，由于使用时经常撞车，现开发一套机房预约系统来解决这个问题
* 
* 1.2身份简介
* 分别有三种身份使用该程序
* 学生代表：申请使用机房
* 教师：审核学生机房申请预约
* 管理员：创建学生代表和教师的账号
* 
* 1.3机房简介
* 机房共有三间
* 1号机房---容量为20人
* 2号机房---容量为50人
* 3号机房---容量为100人
* 
* 1.4申请简介
* 申请的订单每周有管理员负责清空
* 学生可以预约未来一周内的机房使用，预约日期为周一到周五，预约时需选择预约时段（上午、下午）
* 教师来审核，可选择通过或不通过
* 
* 1.5系统具体需求
* 首先进入登入界面，可选身份有
* 学生代表
* 教师
* 管理员
* 退出
* 
* 每个身份都需要验证后，进入子菜单
* 学生需要输入学号、姓名、登入密码
* 教师需要输入职工号、姓名、登入密码
* 管理员需要输入管理员姓名、密码
* 
* 学生具体功能
* 申请预约 --预约机房
* 查看自身预约 --查看自己的预约状态
* 查看所有预约 --查看全部预约信息以及预约状态
* 取消预约 --取消自身预约，预约成功或审核中预约均可取消
* 注销登陆 --退出登陆
* 
* 教师具体功能
* 查看所有预约 -- 查看全部预约消息以及预约状态
* 审核预约 -- 对学生的预约进行审核
* 注销登入 -- 退出登陆
* 
* 管理员具体功能
* 添加账号 -- 添加学生或教师的账号，需要检测学生编号或教师编号是否重复
* 查看账号 -- 可以选择查看学生或教师的全部信息
* 查看机房 -- 查看所有机房信息
* 清空预约 -- 清空所有预约记录
* 注销登陆 -- 退出登陆
*/

#include <iostream>
#include "Identity.h" 
#include "globalFlie.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>
using namespace std;

void managerMenu(Identity*& manager) {
	while (true) {
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1) {
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();
		Teacher* man = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1) {
			cout << "查看所有预约" << endl;
			man->showAllOrder();
		}
		else if (select == 2) {
			cout << "审核预约" << endl;
			man->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void studentMenu(Identity * &student) {
	while (true) {
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showMyorder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->cancelOrder();
		}
		else if (select == 0) {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName,int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()){
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	
	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入教职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
			//else {
			//	id = 0;
			//	break;
			//}
		}
	}
	else if (type == 2) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//cout << fId << " " << fName << " " << fPwd << endl;
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
			//else {
			//	return;
			//}
		}
	}
	else if (type == 3) {
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name,pwd);
				managerMenu(person);
				return;
			}
			//else {
			//	return;
			//}
			}
	}
	cout << "验证登陆失败!" << endl;
	system("pause");
	system("cls");

	return;
}



int main(){
	int select = 0;
	
	while (true) {
		cout << "----------------欢迎来到机房预约系统----------------" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t----------------------------\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       1.学生代表         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       2.教    师         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       3.管 理 员         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       0.退    出         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t----------------------------\n";
		cout << "请输入您的选择" << endl;

		cin >> select;

		switch (select)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		default:
			cout << "输入有误，重新输入" << endl;
			break;
		}
	}
}