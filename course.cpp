#include "course.h"

course::course(QString t_name, int t_credit):
	name(t_name),
	credit(t_credit)
{

}

QString course::getname()
{
	return name;
}

int course::getcredit()
{
	return credit;
}

