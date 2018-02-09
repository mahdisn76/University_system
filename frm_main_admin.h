#ifndef FRM_MAIN_ADMIN_H
#define FRM_MAIN_ADMIN_H

#include<QWidget>
#include<QApplication>
#include<QPushButton>
#include<QGridLayout>

class frm_main_admin : public QWidget
{
	Q_OBJECT

	QGridLayout* gl              = nullptr;

	QPushButton* btn_stds        = nullptr;
	QPushButton* btn_courses     = nullptr;
	QPushButton* btn_std_courses = nullptr;


public:
	explicit frm_main_admin(QWidget *parent = 0);

signals:

public slots:
	void btn_stds_clicked();
	void btn_courses_clicked();
	void btn_std_courses_clicked();
};

#endif // FRM_MAIN_ADMIN_H
