#ifndef STUDENTS_TABLE_H
#define STUDENTS_TABLE_H

#include"student.h"

#include<map>
using namespace std;

class students_table : public map<long long,student> // maybe a bug will happen when student's no bigger than long long int entered
{
public:
	students_table();
};

#endif // STUDENTS_TABLE_H
