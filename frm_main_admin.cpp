#include "frm_main_admin.h"
#include "frm_students_admin.h"
#include "frm_courses_admin.h"

#include <QApplication>
#include<QGridLayout>
#include<QPushButton>

frm_main_admin::frm_main_admin(QWidget *parent) : QWidget(parent)
{
	this->setFixedSize(200,150);

	gl = new QGridLayout;
	btn_stds = new QPushButton("students");
	btn_courses = new QPushButton("courses");
	btn_std_courses = new QPushButton("a student\'s courses");

	gl->addWidget(btn_stds,0,0);
	gl->addWidget(btn_courses,1,0);
	gl->addWidget(btn_std_courses,2,0);

	this->setLayout(gl);

	connect(btn_stds,SIGNAL(clicked()),this,SLOT(btn_stds_clicked()));
	connect(btn_courses,SIGNAL(clicked()),this,SLOT(btn_courses_clicked()));
	connect(btn_std_courses,SIGNAL(clicked()),this,SLOT(btn_std_courses_clicked()));
}

void frm_main_admin::btn_stds_clicked()
{
	this->close();
	frm_students_admin* my_frm_students_admin = new frm_students_admin;
	my_frm_students_admin->show();
}
void frm_main_admin::btn_courses_clicked()
{
	this->close();
	frm_courses_admin* my_frm_courses_admin = new frm_courses_admin;
	my_frm_courses_admin->show();
}

void frm_main_admin::btn_std_courses_clicked()
{

}
