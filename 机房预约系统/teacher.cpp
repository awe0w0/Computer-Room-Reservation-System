#include "teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}

void Teacher::operMenu() {
	cout << "----------------��ӭ��������ԤԼϵͳ----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     1.�鿴����ԤԼ       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       2.���ԤԼ         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.ע����½         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "����������ѡ��" << endl;
}

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		//if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << endl;
		cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << endl;
		cout << "ѧ��id��" << of.m_orderData[i]["stuId"] << endl;
		cout << "ѧ��������" << of.m_orderData[i]["stuName"] << endl;
		cout << "����id��" << of.m_orderData[i]["comId"] << endl;
		///cout << "״̬��" << of.m_orderData[i]["״̬"] << endl;
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else if (of.m_orderData[i]["status"] == "0") {
			status += "��ȡ��";
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}



	cout << "�����ԤԼ����" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" /*|| of.m_orderData[i]["status"] == "2"*/) {
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << endl;
				cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << endl;
				cout << "ѧ��id��" << of.m_orderData[i]["stuId"] << endl;
				cout << "ѧ��������" << of.m_orderData[i]["stuName"] << endl;
				cout << "����id��" << of.m_orderData[i]["comId"] << endl;
				cout << "״̬��" << of.m_orderData[i]["status"] << endl;
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				//else if (of.m_orderData[i]["status"] == "2") {
				//	status += "ԤԼ�ɹ�";
				//}
				cout << status << endl << endl;
			}
			if (v.empty()) {
				cout << endl << "�޴����ԤԼ" << endl;
				system("pause");
				system("cls");
				return;
			}
		//}
	}
	cout << "������Ҫ��˵ļ�¼��0������" << endl;
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
					cout << endl << "1�����ͨ��" << endl << "2��ȡ��ԤԼ" << endl << "0���˳����" << endl;
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
								cout << "�ѳɹ�����" << endl;
								system("pause");
								system("cls");
								return;
							}
							else if (choice == 2) {
								of.m_orderData[v[select - 1]]["status"] = "-1";
								of.save();
								cout << "��ȡ��ԤԼ" << endl;
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
			cout << "����������" << endl;
		}
	}
	system("pause");
	system("cls");
}