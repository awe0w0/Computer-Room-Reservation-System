#include "orderFlie.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		string key;
		string value;
		map<string, string>m;

		int pos1 = date.find(":");
		if (pos1 != -1) {
			key = date.substr(0, pos1);
			value = date.substr(pos1 + 1, date.size() - pos1);
			m.insert(make_pair(key, value));
		}

		int pos2 = interval.find(":");
		if (pos2 != -1) {
			key = interval.substr(0, pos2);
			value = interval.substr(pos2 + 1, interval.size() - pos2);
			m.insert(make_pair(key, value));
		}

		int pos3 = stuId.find(":");
		if (pos3 != -1) {
			key = stuId.substr(0, pos3);
			value = stuId.substr(pos3 + 1, stuId.size() - pos3);
			m.insert(make_pair(key, value));
		}

		int pos4 = stuName.find(":");
		if (pos4 != -1) {
			key = stuName.substr(0, pos4);
			value = stuName.substr(pos4 + 1, stuName.size() - pos4);
			m.insert(make_pair(key, value));
		}

		int pos5 = roomId.find(":");
		if (pos5 != -1) {
			key = roomId.substr(0, pos5);
			value = roomId.substr(pos5 + 1, roomId.size() - pos5);
			m.insert(make_pair(key, value));
		}

		int pos6 = status.find(":");
		if (pos6 != -1) {
			key = status.substr(0, pos6);
			value = status.substr(pos6 + 1, status.size() - pos6);
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
}

void OrderFile::save() {
	if (this->m_Size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out|ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "comId:" << this->m_orderData[i]["comId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}

void OrderFile::updataOrder() {}