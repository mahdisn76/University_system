#include "database.h"
#include "frm_login.h"

#include <QApplication>

database mydatabase;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	frm_login* my_frm_login = new frm_login;
	my_frm_login->show();


	return a.exec();
}
