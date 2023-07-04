#include "student.h"

Student::Student() {}

Student::Student(int id, string name, string pwd) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = pwd;

	this->initStu();
}

void Student::initStu() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}

	ifs.close();
}

void Student::operMenu() {
	cout << "----------------欢迎来到机房预约系统----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       1.申请预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     2.查看个人预约       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     3.查看所有预约       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       4.取消预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.注销登陆         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "请输入您的选择" << endl;
}

void Student::applyOrder() {
	cout << endl;
	cout << "机房开放时间为周一到周五" << endl;
	cout << "请选择预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true) {
		cin >> date;
		if (date < 1 && date > 5) {
			cout << "请再次输入" << endl;
		}
		else {
			break;
		}
	}

	cout << "请输入申请预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true) {
		cin >> interval;
		if (interval != 1 && interval != 2) {
			cout << "请再次输入" << endl;
		}
		else {
			break;
		}
	}

	cout << "请选择机房" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << it->m_ComId << "号机房容量：" << it->m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room < 1 && room>3) {
			cout << "请再次输入" << endl;
		}
		else {
			break;
		}
	}

	ofstream ofs(ORDER_FILE,ios::out|ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "comId:" << room << " ";
	ofs << "status:" << 1 << endl;

	cout << "预约成功，提交审核" << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyorder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "预约日期：周" << of.m_orderData[i]["date"] << endl;
			cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午":"下午") << endl;
			//cout << "学生id：" << of.m_orderData[i]["学生id"] << endl;
			//cout << "学生姓名：" << of.m_orderData[i]["学生姓名"] << endl;
			cout << "机房id：" << of.m_orderData[i]["comId"] << endl;
			//cout << "状态：" << of.m_orderData[i]["状态"] << endl;
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}else if (of.m_orderData[i]["status"] == "-1") {
				status += "预约失败";
			}else if (of.m_orderData[i]["status"] == "0") {
				status += "已取消";
			}
			cout << status << endl<<endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {
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

void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "可以取消的预约：" << endl << "1、审核中" << endl << "2、预约成功" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << endl;
				cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << endl;
				//cout << "学生id：" << of.m_orderData[i]["学生id"] << endl;
				//cout << "学生姓名：" << of.m_orderData[i]["学生姓名"] << endl;
				cout << "机房id：" << of.m_orderData[i]["comId"] << endl;
				//cout << "状态：" << of.m_orderData[i]["状态"] << endl;
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.save();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "请重新输入" << endl;
	}
	system("pause");
	system("cls");
}