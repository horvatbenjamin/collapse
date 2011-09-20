#include "Logger.hpp"
// Global static pointer used to ensure a single instance of the class.
Logger* Logger::m_pInstance = NULL;

/**
 * Singleton constructor of the Logger
 * @return 
 */
Logger* Logger::Instance() {
    if (!m_pInstance) { // Only allow one instance of class to be generated.
        m_pInstance = new Logger;
    }
    return m_pInstance;
}

/**
 * Default constructor
 */
Logger::Logger() {
	_m.set_capacity(10);
}

/**
 * Destruct our Singleton object
 */
void Logger::Destruct() {
    _m.clear();
    delete m_pInstance;//delete pointer
    m_pInstance = 0;
}


/**
 * Log a message
 */
void Logger::log(int level, std::string message){
	/* get time, make a new logmessage object, and push it into the ringbuffer */
	Logmessage newmessage(level,message,Logger::getTime());
	_m.push_back(newmessage);
}

/**
 * Display all log entry
 */
void Logger::list(){ 
	/* get time, make a new logmessage object, and push it into the ringbuffer */
	for(unsigned int i=0;i<_m.size();i++){
	std::cout << _m[i].tostring() << std::endl;
	}
}


/**
 * 
 * @return the current time
 */
time_t Logger::getTime() {
    time_t rawtime;
    time(&rawtime);
    return rawtime;
};
