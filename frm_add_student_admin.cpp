#include "frm_add_student_admin.h"
#include "frm_students_admin.h"
#include "database.h"
#include "mydefs.h"

#include <QLabel>
#include <fstream>
#include <QMessageBox>


extern database mydatabase;

frm_add_student_admin::frm_add_student_admin(QWidget *parent) :
	QWidget(parent)
{

	gl = new QGridLayout;
	txt_no    = new QTextEdit;
	txt_name  = new QTextEdit;
	txt_family= new QTextEdit;
	txt_major = new QTextEdit;
	txt_tel   = new QTextEdit;
	btn_add	  = new QPushButton("add");
	btn_back  = new QPushButton("back");

	gl->addWidget(txt_no    ,0,1);
	gl->addWidget(txt_name  ,1,1);
	gl->addWidget(txt_family,2,1);
	gl->addWidget(txt_major ,3,1);
	gl->addWidget(txt_tel   ,4,1);
	gl->addWidget(btn_add	,5,0);
	gl->addWidget(btn_back  ,5,1);

	gl->addWidget(new QLabel("studet no : "),0,0);
	gl->addWidget(new QLabel("name : "),1,0);
	gl->addWidget(new QLabel("family : "),2,0);
	gl->addWidget(new QLabel("major : "),3,0);
	gl->addWidget(new QLabel("tel : "),4,0);


	txt_no    ->setMaximumSize(110,25);
	txt_name  ->setMaximumSize(110,25);
	txt_family->setMaximumSize(110,25);
	txt_major ->setMaximumSize(110,25);
	txt_tel   ->setMaximumSize(110,25);
	txt_no    ->setTabChangesFocus(true);
	txt_name  ->setTabChangesFocus(true);
	txt_family->setTabChangesFocus(true);
	txt_major ->setTabChangesFocus(true);
	txt_tel   ->setTabChangesFocus(true);

	this->setLayout(gl);

	connect(btn_add,SIGNAL(clicked()),this,SLOT(btn_add_clicked()));
	connect(btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));
}

void frm_add_student_admin::btn_add_clicked()
{
	mydatabase.students.insert(make_pair(txt_no->toPlainText().toLongLong(),student(txt_name->toPlainText(),txt_family->toPlainText(),txt_major->toPlainText(),txt_tel->toPlainText())));

	ofstream fout(filesaddress students_file,ios::app);
	if(mydatabase.students.size()!=0)
		fout<<endl;
	fout<<txt_no->toPlainText().toStdString()<<','<<txt_name->toPlainText().toStdString()<<','<<txt_family->toPlainText().toStdString()<<','<<txt_major->toPlainText().toStdString()<<','<<txt_tel->toPlainText().toStdString();
	fout.close();

	QMessageBox msg;
	msg.setText("added successfuly");
	msg.exec();

	txt_no    ->clear();
	txt_name  ->clear();
	txt_family->clear();
	txt_major ->clear();
	txt_tel   ->clear();

}

void frm_add_student_admin::btn_back_clicked()
{
	this->close();
	frm_students_admin* my_frm_students_admin = new frm_students_admin;
	my_frm_students_admin->show();
}
