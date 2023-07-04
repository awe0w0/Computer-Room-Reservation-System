#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "globalFlie.h"
using namespace std;

class Identity {
public:

	virtual void operMenu() = 0;

	string m_Name;
	string m_Password;
};