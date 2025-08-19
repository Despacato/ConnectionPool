#include <iostream>
#include <memory>
#include "MysqlConn.h"
using namespace std;

int query() {
	MysqlConn conn;
	conn.connect("root", "root", "rose_shop", "127.0.0.1");
	string sql = "insert  person values(5,25,`man`)"
};



int main() {


	return 0;
}