#pragma once
#include <queue>
#include <mutex>
#include "MysqlConn.h"
using namespace std;


class ConnectionPool
{
public:
	static ConnectionPool* getConnectPool();
	ConnectionPool(const ConnectionPool& obj) = delete;
	ConnectionPool& operator=(const ConnectionPool& obj) = delete;
	shared_ptr<MysqlConn> getConnection();
	~ConnectionPool();
private:

	ConnectionPool();
	bool parseJsonFile();
	void produceConnection();
	void recucleConnection();
	void addConnection();

	string m_ip;
	string m_user;
	string m_passwd;
	string m_dbName;
	unsigned short m_port;
	int m_minSize;
	int m_maxSize;
	int m_timeout;
	int m_maxIdleTime;

	queue<MysqlConn*> m_connectionQ;
	mutex m_mutexQ;
	condition_variable m_cond;

};

//单例模式：懒汉模式、饿汉模式
//懒汉模式：当我们需要实例对象的时候才去创建它
//饿汉模式：不管我们用不用实例对象，只要这个类被创建出来了，这个类的实例对象也就有了。

