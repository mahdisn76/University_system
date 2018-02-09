#include "mydefs.h"

#include<string>
#include<fstream>
#include<QMessageBox>

using namespace std;

bool check_user_pass(string user, string pass)
{
	ifstream fin(filesaddress auth_file);
	if(!fin.is_open())
	{
		QMessageBox msg;
		msg.setInformativeText("can not open authunication file\ncontact support");
		msg.setText("ERROR");
		msg.exec();
		//exit(0);
		return false;
	}
	while(!fin.eof())
	{
		string u , p;
		fin>>u>>p;
		if(u==user)
		{
			if(p==pass)
				return true;
			else
				return false;
		}
	}
	return false;
}
