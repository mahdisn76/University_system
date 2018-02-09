#include "student.h"

student::student(QString t_name , QString t_family , QString t_major , QString t_tel):
	name(t_name),
	family(t_family),
	major(t_major),
	tel(t_tel)
{

}

QString student::getname()
{
	return name;
}

QString student::getfamily()
{
	return family;
}

QString student::getmajor()
{
	return major;
}

QString student::gettel()
{
	return tel;
}
