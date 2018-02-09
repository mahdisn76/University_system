#ifndef STUDENT_H
#define STUDENT_H

#include<QString>

class student
{
	QString name;
	QString family;
	QString major;
	QString tel;

public:
	student(QString t_name , QString t_family , QString t_major , QString t_tel);

	QString getname();
	QString getfamily();
	QString getmajor();
	QString gettel();
};

#endif // STUDENT_H
