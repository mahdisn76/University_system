#ifndef FRM_COURSES_ADMIN_H
#define FRM_COURSES_ADMIN_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QGridLayout>

class frm_courses_admin : public QWidget
{
	Q_OBJECT

	QGridLayout* gl = nullptr;
	QTableWidget* tbl_courses    = nullptr;
	QPushButton*  btn_add_course = nullptr;
	QPushButton*  btn_back = nullptr;


	void load_tbl_courses();

public:
	explicit frm_courses_admin(QWidget *parent = 0);

signals:

public slots:
	void btn_add_course_clicked();
	void btn_back_clicked();
};

#endif // FRM_COURSES_ADMIN_H
