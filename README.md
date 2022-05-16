# Bloom

Bloom is a friend finding/dating app. This app is unique from others like it since it shows users a percent compatibility with the other users they see and gives. On the homepage, there is an option to match with someone romanticly or in a friendly way and to decline someone entirely. Once two people match, they are able to open a chat function to talk with one another.

How to compile without using the make file:

Make sure that the browser is in the half screen mode in order for the elements to all be in the correct position (if you are on pc)!!!!!!

compile the three .cpp files needed:
	g++ -Wall -c bloom.cpp
    g++ -Wall -c state.cpp
    g++ -Wall -c server.cpp

link the three .o files:
	g++ -Wall server.o bloom.o state.o /usr/local/cs/cs251/react.o -lcurl

run it using ./a.out


Bloom team - kosier2,loza1
