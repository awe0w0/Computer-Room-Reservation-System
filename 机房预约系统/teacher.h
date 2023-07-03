#pragma once
#include <iostream>
#include "Identity.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Teacher :public Identity {
public:

	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder();

	int m_EmpId;
};