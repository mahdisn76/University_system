#ifndef DATABASE_H
#define DATABASE_H

#include"students_table.h"
#include"courses_table.h"

class database
{
public:
	students_table students;
	course_tables courses;
};

#endif // DATABASE_H
