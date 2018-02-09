#ifndef FRM_STUDENTS_ADMIN_H
#define FRM_STUDENTS_ADMIN_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QGridLayout>


class frm_students_admin : public QWidget
{
	Q_OBJECT

	QGridLayout* gl = nullptr;
	QTableWidget*  tbl_students = nullptr;
	QPushButton* btn_add_student = nullptr;
	QPushButton* btn_back = nullptr;

	void load_tbl_students();

public:
	explicit frm_students_admin(QWidget *parent = 0);
signals:

public slots:

	void btn_add_student_clicked();
	void btn_back_clicked();
};

#endif // FRM_STUDENTS_ADMIN_H
