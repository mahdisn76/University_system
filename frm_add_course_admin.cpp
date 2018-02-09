#include "frm_add_course_admin.h"
#include "frm_courses_admin.h"
#include "database.h"
#include "mydefs.h"

#include <QLabel>
#include <fstream>
#include <QMessageBox>

extern database mydatabase;

frm_add_course_admin::frm_add_course_admin(QWidget *parent) :
	QWidget(parent)
{

	gl = new QGridLayout;
	txt_no    = new QTextEdit;
	txt_name  = new QTextEdit;
	txt_credit = new QTextEdit;
	btn_add	  = new QPushButton("add");
	btn_back  = new QPushButton("back");

	gl->addWidget(txt_no    ,0,1);
	gl->addWidget(txt_name  ,1,1);
	gl->addWidget(txt_credit,2,1);
	gl->addWidget(btn_add	,3,0);
	gl->addWidget(btn_back  ,3,1);

	gl->addWidget(new QLabel("course no : "),0,0);
	gl->addWidget(new QLabel("name : "),1,0);
	gl->addWidget(new QLabel("credit : "),2,0);

	txt_no    ->setMaximumSize(110,25);
	txt_name  ->setMaximumSize(110,25);
	txt_credit->setMaximumSize(110,25);

	txt_no    ->setTabChangesFocus(true);
	txt_name  ->setTabChangesFocus(true);
	txt_credit->setTabChangesFocus(true);

	this->setLayout(gl);

	connect(btn_add,SIGNAL(clicked()),this,SLOT(btn_add_clicked()));
	connect(btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));
}


void frm_add_course_admin::btn_add_clicked()
{
	mydatabase.courses.insert(make_pair(txt_no->toPlainText().toLongLong(),course(txt_name->toPlainText(),txt_credit->toPlainText().toInt())));

	QMessageBox msg;

	ofstream fout(filesaddress courses_file,ios::app);
	if(!fout.is_open())
	{
		msg.setText("can not open courses file");
		msg.exec();
		return;
	}
	if(mydatabase.courses.size()!=0)
		fout<<endl;

	fout<<txt_no->toPlainText().toStdString()<<','<<txt_name->toPlainText().toStdString()<<','<<txt_credit->toPlainText().toStdString();

	msg.setText("added successfuly");
	msg.exec();

	txt_no    ->clear();
	txt_name  ->clear();
	txt_credit->clear();

	fout.close();
}

void frm_add_course_admin::btn_back_clicked()
{
	this->close();
	frm_courses_admin* my_frm_courses_admin= new frm_courses_admin;
	my_frm_courses_admin->show();
}


