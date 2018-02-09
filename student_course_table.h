#ifndef STUDENT_COURSE_TABLE_H
#define STUDENT_COURSE_TABLE_H

#include "student_course.h"

#include<map>
using namespace std;

class student_course_table : public map<long long , student_course>
{
public:
	student_course_table();
};

#endif // STUDENT_COURSE_TABLE_H
