#include "courses_table.h"
#include "mydefs.h"
#include "course.h"

#include <QMessageBox>
#include <fstream>
#include <QString>

course_tables::course_tables()
{
	ifstream fin(filesaddress courses_file);
	if(!fin.is_open())
	{
		QMessageBox msg;
		msg.setText("can not open courses file");
		msg.exec();
		exit(0);
	}
	while(!fin.eof())
	{
		string tmp;
		getline(fin,tmp);
		QStringList const elems = QString::fromStdString(tmp).trimmed().split(',');
		if(elems.size()!=3)
			continue;

		this->insert(make_pair(elems[0].toLongLong(),course(elems[1],elems[2].toInt())));
	}

}
