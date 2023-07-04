#pragma once
#include <iostream>
#include "myPrint.hpp"
#include "Identity.h"
using namespace std;

class Manager :public Identity {
public:

	Manager();

	Manager(string name, string pwd);

	virtual	void operMenu();

	void addPerson();

	void initVector();

	bool checkRepeat(int id, int type);

	void showPerson();

	void showComputer();

	void cleanFile();

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};