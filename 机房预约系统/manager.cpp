#include "manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Password = pwd;
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

	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ��";
	}
	else {
		filename = TEACHER_FILE;
		tip = "�������ְ����";

	}
	ofs.open(filename, ios::out|ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Manager::showPerson() {}

void Manager::showComputer() {}

void Manager::cleanFile() {}