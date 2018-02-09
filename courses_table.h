#ifndef COURSE_TABLE_H
#define COURSE_TABLE_H

#include"course.h"

#include<map>
using namespace std;

class course_tables : public map<long long , course> // maybe a bug will happen when a course's no bigger than long long int entered
{
public:
	course_tables();
};

#endif // COURSE_TABLE_H
