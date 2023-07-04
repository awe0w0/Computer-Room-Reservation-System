#pragma once
#include <iostream>
using namespace std;

#include <map>
#include <string>
#include <fstream>
#include "globalFlie.h"

class OrderFile {
public:
	OrderFile();

	void updataOrder();

	void save();

	map<int, map<string, string>>m_orderData;

	int m_Size;
};