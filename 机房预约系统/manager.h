#pragma once
#include <iostream>
#include "student.h"
#include "teacher.h"
#include "Identity.h"
using namespace std;

class Manager :public Identity {
public:

	Manager();

	Manager(string name, string pwd);

	virtual	void operMenu();

	void addPerson();

	void initVector();

	void showPerson();

	void showComputer();

	void cleanFile();

	vector<Student> vStu;

	vector<Teacher> vTea;
};