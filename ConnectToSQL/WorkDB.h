#pragma once
#include "Lib.h"

wstring makeQuery(int a);
wstring deleteFromTB();
wstring insertToTB();

class WorkDB
{
private:

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];


public:
	void connectToDB();
	void disconnectDB();
	
	void query(int a);
	
	WorkDB();
	~WorkDB();
};


