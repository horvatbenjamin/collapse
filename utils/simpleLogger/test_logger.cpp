#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Logger.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	std::cout << "---- Starting Logger test app ----" << std::endl;
	srand ( time(NULL) );
	int l;
	/* Start our Collector singleton*/
    	Logger::Instance();
	std::cout << "---- Adding some log entrys to our ringbuffer ----" << std::endl;	
	/* add 7 log entry */
	for(unsigned int i=0;i<7;i++){
		l = rand() % 3 + 1; //generate random lvl	
		Logger::Instance()->log(l,"This is a log entry");

	}
	std::cout << "---- Ringbuffer ----" << std::endl;	
	Logger::Instance()->list();
		sleep(rand()%5);
	/* add 5 more */
	for(unsigned int i=0;i<5;i++){
		l = rand() % 3 + 1; //generate random lvl	
		Logger::Instance()->log(l,"This is a log entry");
	}
	std::cout << "---- Ringbuffer ----" << std::endl;
	Logger::Instance()->list();	
}
