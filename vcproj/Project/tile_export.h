#ifndef RME_TILE_EXPORT_H_
#define RME_TILE_EXPORT_H_
#include "sqlite3.h"
#include <stdio.h>
#include <iostream>
#include <string>


static int createDB(const char* s) {
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);
}

static int createTable(const char* s) {
	sqlite3* DB;
	int exit = 0;

	std::string sql = "CREATE TABLE IF NOT EXIST ITEMS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"X INTEGER NOT NULL, "
		"Y INTEGER NOT NULL, "
		"Z INTEGER NOT NULL, "
		"items TEXT NOT NULL";

	exit = sqlite3_open(s, &DB);
	char* messageError;
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {

	}
	else {
		std::cout << "Table created succesffullt" << std::endl;
		sqlite3_close(DB);
	}
}
#endif

