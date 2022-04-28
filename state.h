#ifndef __STATE_H__
#define __STATE_H__

#include<string>
#include "user.h"
using namespace std;

class State{
    Account potmatch;
    int percentMatch, numFields, bioLength, nameLength, popUpTextLength;
    string popUpText;
    char showPopUp, pageTitle;

    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: M- main page, L- chat list, C- user chat

    public:
    Account &getAccount() {return potmatch;}
    char getShowPopUp() {return showPopUp;}
    char getPageTitle() const {return pageTitle;}
    int getPercentMatch() const {return percentMatch;}
    int offset(string text) const;
    string getPopUpText()const{return popUpText;}
    void read_from(const char *mem);
    void write_to(char *mem);
};

void display(const State &state);

#endif
