#include "WorkDB.h"


WorkDB::WorkDB() {
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
};

WorkDB::~WorkDB()
{
}

void WorkDB::connectToDB()
{
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		disconnectDB();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		disconnectDB();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		disconnectDB();

	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";

	//connect to SQL Server	
	//I am using a trusted connection and port 14808
	//it does not matter if you are using default or named instance
	//just make sure you define the server name and the port
	//You have the option to use a username/password instead of a trusted connection
	//but is more secure to use a trusted connection
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;UID=username;PWD=password;",
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1434;DATABASE=DB1;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		disconnectDB();

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		disconnectDB();

	default:
		break;
	}

	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		disconnectDB();

}

void WorkDB::disconnectDB()
{
	//close connection and free resources
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
};

void WorkDB::query(int a)
{

	//output
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";

	//if there is a problem executing the query then exit application
	//else display query result

	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)makeQuery(a).c_str(), SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		disconnectDB();
	}
	else {

		//declare output variable and pointer
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

			//display query result
			cout << "\nQuery Result:\n\n";
			cout << sqlVersion << endl;

		}
	}
};

wstring makeQuery(int a)
{
	wstring q;

	switch (a)
	{
	case 1:
		q = deleteFromTB();
		break;
	case 2:
		q = insertToTB();
		break;
	default:
		break;
	}

	//q += w;

	return q;
}

wstring deleteFromTB()
{
	wstring w;
	cout << "Enter id to delete: ";

	wcin >> w;

	w = L"delete from TB1 where id=" + w;
	return w;
}

wstring insertToTB()
{
	wstring w;
	cout << "Enter id to insert: ";

	wcin >> w;

	w = L"insert into TB1(id)values(" + w + L")";
	return w;
}