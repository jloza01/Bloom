#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
    int percentMatch, age;
    string theirName, yourName, bio;
    bool showPopUp;

    public:
    bool getPopUp(){return showPopUp;}
    int getPercentMatch(){return percentMatch;}
    int getAge(){return age;}
    string getYourName(){return yourName;}
    string getTheirName(){return theirName;}
    string getBio(){return bio;}
    void read_from(const char *mem);
    void write_to(char *mem);
};

#endif