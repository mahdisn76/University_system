#ifndef COURSE_H
#define COURSE_H

#include<QString>

class course
{
	QString name;
	int credit; //vahed
public:
	course(QString,int);
	QString getname();
	int getcredit();
};

#endif // COURSE_H
