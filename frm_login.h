#ifndef FRM_LOGIN_H
#define FRM_LOGIN_H

#include<QApplication>
#include <QWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QTextEdit>


class frm_login : public QWidget
{
	Q_OBJECT

	QPushButton* btn_ok=nullptr;
	QPushButton* btn_cancel=nullptr;
	QTextEdit*   txt_username=nullptr;
	QTextEdit*   txt_password=nullptr;
	QGridLayout* grd=nullptr;
public:
	explicit frm_login(QWidget *parent = 0);

signals:

public slots:
	void btn_ok_clicked();
	void btn_cancel_clicked();
};

#endif // FRM_LOGIN_H
