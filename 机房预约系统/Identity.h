#pragma once
#include <iostream>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

class Identity {
public:

	virtual void operMenu() = 0;

	string m_Name;
	string m_Password;
};