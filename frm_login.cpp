#include "frm_login.h"
#include "check_user_pass.h"
#include "frm_main_admin.h"

#include<QApplication>
#include<QPushButton>
#include<QTextEdit>
#include<QGridLayout>
#include<QLabel>
#include<QMessageBox>

frm_login::frm_login(QWidget *parent) : QWidget(parent)
{
	this->setWindowTitle("Login");
	//this->setFixedSize(250,120);

	btn_ok		 = new QPushButton("OK");
	btn_cancel   = new QPushButton("cancel");
	txt_username = new QTextEdit();
	txt_password = new QTextEdit();
	grd			 = new QGridLayout();

	txt_username->setMaximumSize(110,25);
	txt_username->setTabChangesFocus(true);
	txt_password->setMaximumSize(110,25);
	txt_password->setTabChangesFocus(true);


	grd->addWidget((new QLabel("username : ")),0,0);
	grd->addWidget(txt_username,0,1);
	grd->addWidget(new QLabel("password : "),1,0);
	grd->addWidget(txt_password,1,1);
	grd->addWidget(btn_ok,2,0);
	grd->addWidget(btn_cancel,2,1);
	this->setLayout(grd);

	connect(btn_ok,SIGNAL(clicked()),this,SLOT(btn_ok_clicked()));
	connect(btn_cancel,SIGNAL(clicked()),SLOT(btn_cancel_clicked()));
}

void frm_login::btn_ok_clicked()
{
	bool auth_status;  //  true : login ok
					   // false : login failed
	
	auth_status = check_user_pass(txt_username->toPlainText().toStdString(),txt_password->toPlainText().toStdString());
	if(auth_status)
	{
		this->close();
		if(txt_username->toPlainText()=="admin") // if admin entered
		{
			frm_main_admin* my_frm_main_admin=new frm_main_admin;
			my_frm_main_admin->show();
		}
		else
		{
			// ...
		}
	}
	else
	{
		QMessageBox msg;
		msg.setText("wrong username or password");
		msg.exec();
		txt_username->clear();
		txt_password->clear();
		txt_username->setFocus();
	}
}

void frm_login::btn_cancel_clicked()
{
	exit(0);
}
