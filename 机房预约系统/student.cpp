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
	cout << "----------------��ӭ��������ԤԼϵͳ----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       1.����ԤԼ         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     2.�鿴����ԤԼ       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|     3.�鿴����ԤԼ       |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       4.ȡ��ԤԼ         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.ע����½         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "����������ѡ��" << endl;
}

void Student::applyOrder() {
	cout << endl;
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "��ѡ��ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true) {
		cin >> date;
		if (date < 1 && date > 5) {
			cout << "���ٴ�����" << endl;
		}
		else {
			break;
		}
	}

	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true) {
		cin >> interval;
		if (interval != 1 && interval != 2) {
			cout << "���ٴ�����" << endl;
		}
		else {
			break;
		}
	}

	cout << "��ѡ�����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << it->m_ComId << "�Ż���������" << it->m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room < 1 && room>3) {
			cout << "���ٴ�����" << endl;
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

	cout << "ԤԼ�ɹ����ύ���" << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyorder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << endl;
			cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����":"����") << endl;
			//cout << "ѧ��id��" << of.m_orderData[i]["ѧ��id"] << endl;
			//cout << "ѧ��������" << of.m_orderData[i]["ѧ������"] << endl;
			cout << "����id��" << of.m_orderData[i]["comId"] << endl;
			//cout << "״̬��" << of.m_orderData[i]["״̬"] << endl;
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}else if (of.m_orderData[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}else if (of.m_orderData[i]["status"] == "0") {
				status += "��ȡ��";
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

void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ȡ����ԤԼ��" << endl << "1�������" << endl << "2��ԤԼ�ɹ�" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << endl;
				cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << endl;
				//cout << "ѧ��id��" << of.m_orderData[i]["ѧ��id"] << endl;
				//cout << "ѧ��������" << of.m_orderData[i]["ѧ������"] << endl;
				cout << "����id��" << of.m_orderData[i]["comId"] << endl;
				//cout << "״̬��" << of.m_orderData[i]["״̬"] << endl;
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "����������" << endl;
	}
	system("pause");
	system("cls");
}