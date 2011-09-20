#ifndef LOGMESSAGE_HPP
#define	LOGMESSAGE_HPP
#include <string>
#include <sstream>
class Logmessage {
public:
	Logmessage(int level,std::string message,time_t rtime);
	std::string tostring();
	
private:
	int _level;	
	std::string _message;
	time_t _rtime; //rawtime!
};
#endif
