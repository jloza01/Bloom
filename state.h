#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
    int percentMatch, age, numMatches, numFields, bioLength, nameLength, popUpTextLength;
    string name, bio, popUpText;
    char showPopUp, pageTitle;

    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: M- main page, L- chat list, C- user chat

    public:
    char getShowPopUp() const {return showPopUp;}
    char getPageTitle() const {return pageTitle;}
    int getPercentMatch() const {return percentMatch;}
    int getAge() const{return age;}
    int getnumMatches() const {return numMatches;}
    int offset(string text);
    string getPopUpText()const{return popUpText;}
    string getName() const{return name;}
    string getBio() const{return bio;}
    void read_from(const char *mem);
    void write_to(char *mem);
};


void display(const State &state);

#endif
