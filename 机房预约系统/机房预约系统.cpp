/*����ԤԼϵͳ
*1.1ϵͳ���
* ѧУ���м�����ͬ���Ļ���������ʹ��ʱ����ײ�����ֿ���һ�׻���ԤԼϵͳ������������
* 
* 1.2��ݼ��
* �ֱ����������ʹ�øó���
* ѧ����������ʹ�û���
* ��ʦ�����ѧ����������ԤԼ
* ����Ա������ѧ������ͽ�ʦ���˺�
* 
* 1.3�������
* ������������
* 1�Ż���---����Ϊ20��
* 2�Ż���---����Ϊ50��
* 3�Ż���---����Ϊ100��
* 
* 1.4������
* ����Ķ���ÿ���й���Ա�������
* ѧ������ԤԼδ��һ���ڵĻ���ʹ�ã�ԤԼ����Ϊ��һ�����壬ԤԼʱ��ѡ��ԤԼʱ�Σ����硢���磩
* ��ʦ����ˣ���ѡ��ͨ����ͨ��
* 
* 1.5ϵͳ��������
* ���Ƚ��������棬��ѡ�����
* ѧ������
* ��ʦ
* ����Ա
* �˳�
* 
* ÿ����ݶ���Ҫ��֤�󣬽����Ӳ˵�
* ѧ����Ҫ����ѧ�š���������������
* ��ʦ��Ҫ����ְ���š���������������
* ����Ա��Ҫ�������Ա����������
* 
* ѧ�����幦��
* ����ԤԼ --ԤԼ����
* �鿴����ԤԼ --�鿴�Լ���ԤԼ״̬
* �鿴����ԤԼ --�鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
* ȡ��ԤԼ --ȡ������ԤԼ��ԤԼ�ɹ��������ԤԼ����ȡ��
* ע����½ --�˳���½
* 
* ��ʦ���幦��
* �鿴����ԤԼ -- �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
* ���ԤԼ -- ��ѧ����ԤԼ�������
* ע������ -- �˳���½
* 
* ����Ա���幦��
* ����˺� -- ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦ����Ƿ��ظ�
* �鿴�˺� -- ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
* �鿴���� -- �鿴���л�����Ϣ
* ���ԤԼ -- �������ԤԼ��¼
* ע����½ -- �˳���½
*/

#include <iostream>
#include "Identity.h" 
#include "globalFlie.h"
#include <fstream>
using namespace std;

void LoginIn(string fileName,int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()){
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "�������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && ifs >> fPwd) {
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				person = new Student(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 2) {
		
	}
	else if (type == 3) {
		
	}
	cout << "��֤��½ʧ��!" << endl;

	return;
}

int main(){
	int select = 0;
	
	while (true) {
		cout << "----------------��ӭ��������ԤԼϵͳ----------------" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t----------------------------\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       1.ѧ������         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       2.��    ʦ         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       3.�� �� Ա         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|       0.��    ��         |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t----------------------------\n";
		cout << "����������ѡ��" << endl;

		cin >> select;

		switch (select)
		{
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
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
			cout << "����������������" << endl;
			break;
		}
	}
}