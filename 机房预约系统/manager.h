#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class Manager :public Identity {
public:

	Manager();

	Manager(string name, string pwd);

	virtual	void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();
};