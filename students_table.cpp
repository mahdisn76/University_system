#include "students_table.h"
#include "mydefs.h"

#include<fstream>
#include<QMessageBox>
#include<string>
#include<QString>

using namespace std;

students_table::students_table()
{
	ifstream fin(filesaddress students_file);
	if(!fin.is_open())
	{
		QMessageBox msg;
		msg.setText("can not open students file");
		msg.exec();
		exit(0);
	}

	while(!fin.eof())
	{
		string tmp;
		getline(fin,tmp);
		QStringList const elems = QString::fromStdString(tmp).trimmed().split(',');

		if(elems.size()!=5)
			continue;

		this->insert(make_pair(elems[0].toLongLong(),student(elems[1],elems[2],elems[3],elems[4])));
	}
}
