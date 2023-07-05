#include "teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}

void Teacher::operMenu() {
	cout << "----------------欢迎来到机房预约系统----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     1.查看所有预约       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       2.审核预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.注销登陆         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "请输入您的选择" << endl;
}

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		//if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
		cout << "预约日期：周" << of.m_orderData[i]["date"] << endl;
		cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << endl;
		cout << "学生id：" << of.m_orderData[i]["stuId"] << endl;
		cout << "学生姓名：" << of.m_orderData[i]["stuName"] << endl;
		cout << "机房id：" << of.m_orderData[i]["comId"] << endl;
		///cout << "状态：" << of.m_orderData[i]["状态"] << endl;
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "预约失败";
		}
		else if (of.m_orderData[i]["status"] == "0") {
			status += "已取消";
		}
		cout << status << endl << endl;
		//}
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}



	cout << "待审核预约如下" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" /*|| of.m_orderData[i]["status"] == "2"*/) {
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << endl;
				cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << endl;
				cout << "学生id：" << of.m_orderData[i]["stuId"] << endl;
				cout << "学生姓名：" << of.m_orderData[i]["stuName"] << endl;
				cout << "机房id：" << of.m_orderData[i]["comId"] << endl;
				cout << "状态：" << of.m_orderData[i]["status"] << endl;
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				//else if (of.m_orderData[i]["status"] == "2") {
				//	status += "预约成功";
				//}
				cout << status << endl << endl;
			}
			if (v.empty()) {
				cout << endl << "无待审核预约" << endl;
				system("pause");
				system("cls");
				return;
			}
		//}
	}
	cout << "请输入要审核的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				int choice = 0;
				while (true) {
					cout << endl << "1、审核通过" << endl << "2、取消预约" << endl << "0、退出审核" << endl;
					cin >> choice;
					if (choice == 1 || choice == 2 || choice == 0) {
						if (choice == 0) {
							system("pause");
							system("cls");
							return;
						}
						else {
							if (choice == 1) {
								of.m_orderData[v[select - 1]]["status"] = "2";
								of.save();
								cout << "已成功审批" << endl;
								system("pause");
								system("cls");
								return;
							}
							else if (choice == 2) {
								of.m_orderData[v[select - 1]]["status"] = "-1";
								of.save();
								cout << "已取消预约" << endl;
								system("pause");
								system("cls");
								return;
							}
						}
					}
				}
			}
		}
		else {
			cout << "请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}