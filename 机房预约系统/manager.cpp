#include "manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Password = pwd;

	this->initVector();
}

void Manager::operMenu() {
	cout << "----------------��ӭ��������ԤԼϵͳ----------------" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       1.����˺�         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       2.�鿴�˺�         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       3.�鿴����         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       4.���ԤԼ         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|       0.ע����½         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "����������ѡ��" << endl;
}

void Manager::addPerson() {
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.��ӽ�ʦ" << endl;
	string filename;
	string tip;
	ofstream ofs;
	string errorTip;

	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ��";
		errorTip = "ѧ���ظ������ٴ�����";
	}
	else {
		filename = TEACHER_FILE;
		tip = "�������ְ����";
		errorTip = "��ְ�����ظ������ٴ�����";
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
	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	this->initVector();

	ofs.close();
	system("pause");
	system("cls");
}

void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();
	vCom.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vTea.size() << endl;
	ifs.close();

	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ" << vCom.size() << endl;
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
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1) {
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), myPrint());
		system("pause");
		system("cls");
	}else if (select == 2) {
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), myPrint());
		system("pause");
		system("cls");
	}
}

void Manager::showComputer() {
	cout << "������Ϣ����" << endl;
	for_each(vCom.begin(), vCom.end(), myPrint());
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}