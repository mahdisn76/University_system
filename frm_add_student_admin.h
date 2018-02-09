#ifndef FRM_ADD_STUDENT_ADMIN_H
#define FRM_ADD_STUDENT_ADMIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

class frm_add_student_admin : public QWidget
{
	Q_OBJECT
	QGridLayout* gl = nullptr;
	QTextEdit* txt_no ;
	QTextEdit* txt_name;
	QTextEdit* txt_family;
	QTextEdit* txt_major;
	QTextEdit* txt_tel;
	QPushButton* btn_add;
	QPushButton* btn_back;

public:
	explicit frm_add_student_admin(QWidget *parent = 0);

signals:

public slots:
	void btn_add_clicked();
	void btn_back_clicked();
};

#endif // FRM_ADD_STUDENT_ADMIN_H
