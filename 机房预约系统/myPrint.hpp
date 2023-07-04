#include <iostream>
#include "student.h"
#include"teacher.h"
#include "computerRoom.h"

class myPrint {
public:
	 void operator()(Student &s) {
		 std::cout << "学号 " << s.m_Id << " 姓名 " << s.m_Name << " 密码 " << s.m_Password << std::endl;
	}

	 void operator()(Teacher& t) {
		 std::cout << "教职工号 " << t.m_EmpId << " 姓名 " << t.m_Name << " 密码 " << t.m_Password << std::endl;
	 }

	 void operator()(ComputerRoom &c) {
		 std::cout << "机房号 " << c.m_ComId << " 机房容量 " << c.m_MaxNum << endl;
	 }
};