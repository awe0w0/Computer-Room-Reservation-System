#pragma once
#include <iostream>
#include "computerRoom.h"
#include "Identity.h"
using namespace std;

class Student :public Identity {
public:
	Student();

	Student(int	id, string name, string pwd);

	void initStu();

	virtual void operMenu();

	virtual void applyOrder();

	void showMyorder();

	void showAllOrder();

	void cancelOrder();

	vector<ComputerRoom> vCom;

	int m_Id;
};