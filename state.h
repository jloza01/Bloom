#ifndef __STATE_H__
#define __STATE_H__
#include "user.h"

#include<string>
#include "user.h"
using namespace std;

class State{
    Account you, potmatch;
    int percentMatch, bioLength, nameLength, popUpTextLength;
    string popUpText;
    char showPopUp, pageTitle;

    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: M- main page, I- chat inbox, C- user chat

    public:
    Account &getMatchAccount() {return potmatch;}
    Account &getYourAccount() {return you;}
    char getShowPopUp() {return showPopUp;}
    char getPageTitle()  {return pageTitle;}
    int getPercentMatch()  {return percentMatch;}
    int offset(string text) ;
    string getPopUpText(){return popUpText;}
    void read_from(char *mem);
    void write_to(char *mem);
    void update();
};

void display( State &state);

#endif
