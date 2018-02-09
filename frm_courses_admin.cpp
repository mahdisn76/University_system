#include "frm_main_admin.h"
#include "frm_courses_admin.h"
#include "frm_add_course_admin.h"
#include "mydefs.h"
#include "database.h"

#include <QApplication>

extern database mydatabase;

frm_courses_admin::frm_courses_admin(QWidget *parent) :
	QWidget(parent)
{
	this->setFixedSize(340,500);

	gl= new QGridLayout;
	tbl_courses = new QTableWidget(mydatabase.courses.size(),3,this);
	btn_add_course = new QPushButton("add new course");
	btn_back = new QPushButton("back");

	gl->addWidget(tbl_courses,0,0,0,2);
	gl->addWidget(btn_add_course,1,0);
	gl->addWidget(btn_back,1,1);

	QStringList tbl_courses_hdrs;
	tbl_courses_hdrs << "course no" << "name" << "credit" ;
	tbl_courses->setHorizontalHeaderLabels(tbl_courses_hdrs);
	tbl_courses->setEditTriggers(QAbstractItemView::NoEditTriggers);

	connect(btn_add_course,SIGNAL(clicked()),this,SLOT(btn_add_course_clicked()));
	connect(btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));

	this->setLayout(gl);

	load_tbl_courses();
}

void frm_courses_admin::load_tbl_courses()
{
	int i=0;
	for(auto itr=mydatabase.courses.begin() ; itr!=mydatabase.courses.end() ; itr++)
	{
		tbl_courses->setItem(i,0,new QTableWidgetItem(QString::number(itr->first)));
		tbl_courses->setItem(i,1,new QTableWidgetItem(itr->second.getname()));
		tbl_courses->setItem(i,2,new QTableWidgetItem(QString::number(itr->second.getcredit())));

		i++;
	}
}

void frm_courses_admin::btn_add_course_clicked()
{
	this->close();
	frm_add_course_admin* my_frm_add_course_admin = new frm_add_course_admin;
	my_frm_add_course_admin->show();
}

void frm_courses_admin::btn_back_clicked()
{
	this->close();
	frm_main_admin* my_frm_main_admin = new frm_main_admin;
	my_frm_main_admin->show();
}
