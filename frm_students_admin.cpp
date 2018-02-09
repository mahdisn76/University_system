#include "frm_students_admin.h"
#include "frm_main_admin.h"
#include "frm_add_student_admin.h"
#include "database.h"

#include <QApplication>
#include <QTableWidget>
#include <QWidgetItem>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <map>


using namespace std;

extern database mydatabase;

frm_students_admin::frm_students_admin(QWidget *parent) :
	QWidget(parent)
{
	this->setFixedSize(540,500);

	gl = new QGridLayout;
	tbl_students = new QTableWidget(mydatabase.students.size(),5,this);
	btn_add_student = new QPushButton("add new student");
	btn_back = new QPushButton("back");

	QStringList tbl_students_hdrs;
	tbl_students_hdrs << "student no" << "name" << "family" << "major" << "tel" ;
	tbl_students->setHorizontalHeaderLabels(tbl_students_hdrs);
	tbl_students->setEditTriggers(QAbstractItemView::NoEditTriggers);

	gl->addWidget(tbl_students,0,0,0,2);

	gl->addWidget(btn_add_student,1,0);
	gl->addWidget(btn_back,1,1);



	this->setLayout(gl);

	load_tbl_students();

	connect(btn_add_student,SIGNAL(clicked()),this,SLOT(btn_add_student_clicked()));
	connect(btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));
}

void frm_students_admin::load_tbl_students()
{
	int i=0;
	for(auto itr = mydatabase.students.begin() ; itr != mydatabase.students.end() ; itr++)
	{
		tbl_students->setItem(i,0,new QTableWidgetItem(QString::number(itr->first)));
		tbl_students->setItem(i,1,new QTableWidgetItem(itr->second.getname()));
		tbl_students->setItem(i,2,new QTableWidgetItem(itr->second.getfamily()));
		tbl_students->setItem(i,3,new QTableWidgetItem(itr->second.getmajor()));
		tbl_students->setItem(i,4,new QTableWidgetItem(itr->second.gettel()));

		i++;
	}
}

void frm_students_admin::btn_add_student_clicked()
{
	this->close();
	frm_add_student_admin* my_frm_add_student_admin = new frm_add_student_admin;
	my_frm_add_student_admin->show();
}

void frm_students_admin::btn_back_clicked()
{
	this->close();
	frm_main_admin * my_frm_main_admin = new frm_main_admin;
	my_frm_main_admin->show();
}
