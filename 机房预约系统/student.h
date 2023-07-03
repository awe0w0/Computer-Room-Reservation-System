#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class Student :public Identity {
public:
	Student();

	Student(int	id, string name, string pwd);

	virtual void operMenu();

	virtual void applyOrder();

	void applyOrder();

	void showMyorder();

	void showAllOrder();

	void cancelOrder();

	int m_Id;
};