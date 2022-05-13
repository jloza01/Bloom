server:  bloom.o state.o server.o
	g++ -Wall server.o bloom.o state.o /usr/local/cs/cs251/react.o -lcurl

bloom.o:  bloom.cpp user.h
	g++ -Wall -c bloom.cpp

state.o:  state.cpp state.h user.h message.h
	g++ -Wall -c state.cpp

server.o:  server.cpp state.cpp state.h
	g++ -Wall -c server.cpp