#include <iostream>
#include "student.h"
#include"teacher.h"
#include "computerRoom.h"

class myPrint {
public:
	 void operator()(Student &s) {
		 std::cout << "ѧ�� " << s.m_Id << " ���� " << s.m_Name << " ���� " << s.m_Password << std::endl;
	}

	 void operator()(Teacher& t) {
		 std::cout << "��ְ���� " << t.m_EmpId << " ���� " << t.m_Name << " ���� " << t.m_Password << std::endl;
	 }

	 void operator()(ComputerRoom &c) {
		 std::cout << "������ " << c.m_ComId << " �������� " << c.m_MaxNum << endl;
	 }
};