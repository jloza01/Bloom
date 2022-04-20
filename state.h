#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
    int percentMatch, age, numMatches;
    string name, bio, popUpText;
    char showPopUp;

    public:
    char getPopUp(){return showPopUp;}
    int getPercentMatch(){return percentMatch;}
    int getAge(){return age;}
    int getnumMatches(){return numMatches;}
    string getPopUpText(){return popUpText;}
    string getName(){return name;}
    string getBio(){return bio;}
    void read_from(const char *mem);
    void write_to(char *mem);
    void display();
};

#endif