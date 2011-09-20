#include "Logmessage.hpp"
/**
* Logmessage constructor
* @param level The loglevel (e.g. Warning, Error)
* @param message The message (e.g. can't open file)
* @param rtime The raw time of the message
*/
Logmessage::Logmessage(int level,std::string message,time_t rtime) {
	_level = level;
	_message = message;
	_rtime = rtime;
}
/**
* return a log entry in string format
* @return string
*/
std::string Logmessage::tostring() {
	std::stringstream temp;
	struct tm *d = localtime(&_rtime);
	temp << d->tm_year+1900 << "-" << d->tm_mon << "-" << d->tm_mday << "-" << d->tm_hour << ":" << d->tm_min << ":" << d->tm_sec;
	temp << _level << " -- " << _message;
	return temp.str();
}
