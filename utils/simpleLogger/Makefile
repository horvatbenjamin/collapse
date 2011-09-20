# MakeFile

BOOST_DIR=/usr/src/boost_1_47_0/
LDFLAGS+=-I $(BOOST_DIR)
#LIBS+=-Wl,-rpath-link=$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/usr/lib/mysql -lmysqlclient
#CUSTOMFLAGS=-lmysqlclient -I $(COMMON)

OBJECTS=Logmessage.o Logger.o test_logger.o 


all: Logger

debug: CXX += -DDEBUG -g
debug: CC += -DDEBUG -g
debug: Logger

Logger: $(OBJECTS)
	$(CXX) $(CUSTOMFLAGS) $(LDFLAGS) $(CXXFLAGS) -o logger_test $(OBJECTS) $(LIBS) 
Logger.o: Logger.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -c Logger.cpp $(LIBS)
Logmessage.o: Logmessage.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -c Logmessage.cpp $(LIBS)
test_logger.o: test_logger.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -c test_logger.cpp $(LIBS)

# remove object files and executable when user executes "make clean"

clean:
	rm -rf *.o logger_test
re: clean all
