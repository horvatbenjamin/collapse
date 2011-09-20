#ifndef LOGGER_HPP
#define	LOGGER_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Logmessage.hpp"
#include <boost/circular_buffer.hpp>

#define BUFFER 300

// Singleton logger object
class Logger {
public:
	static Logger* Instance();
	void log(int level, std::string message); 
	void Destruct();//destruct our singleton
    	//void setlogdir(std::string logdirectory);
	void list();//list all the log entrys in our buffer (max BUFFER)
	//void list(int number);//list number log entrys
	time_t getTime();
private:
	Logger(); // Private so that it can  not be called
	Logger(Logger const&) {}; // copy constructor is private
	Logger& operator=(Logger const&) {}; // assignment operator is private
	static Logger* m_pInstance;
	//std::string _logdirectory;
	boost::circular_buffer<Logmessage> _m;

};
#endif
