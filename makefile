#target: dependencies
#	rule to build

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS = containerMain.o containerMenu.o menuValidation.o queue.o stack.o
SRCS = containerMain.cpp containerMenu.cpp menuValidation.cpp queue.cpp stack.cpp
HEADERS = containerMenu.hpp menuValidation.hpp queue.hpp stack.hpp
containers: ${OBJS}
	${CXX} ${CXXFLAGS} -o containers containerMain.o containerMenu.o menuValidation.o queue.o stack.o
containerMain.o: containerMain.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} -c containerMain.cpp containerMenu.cpp menuValidation.cpp queue.cpp stack.cpp

clean: ${OBJS}
	-rm *.o ${OBJS} containers
