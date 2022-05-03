#ifndef __STATE_H__
#define __STATE_H__

#include<string>
#include "user.h"
using namespace std;

class State{
    Account you, potmatch;
    int percentMatch, bioLength, nameLength, popUpTextLength, showPopUp, pageTitle;
    string popUpText;

    //labels text
    string yourProfileLab, bioLab, ageLab, matchPercentLab;
    
    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: 0- main page, 1- chat inbox, 1- user chat

    public:
    Account &getMatchAccount() {return potmatch;}
    Account &getYourAccount() {return you;}
    int getShowPopUp() {return showPopUp;}
    int getPageTitle()  {return pageTitle;}
    int getPercentMatch()  {return percentMatch;}
    int offset(string text);
    int label_offset();
    string getPopUpText(){return popUpText;}
    string getYourProfileLab() {return yourProfileLab;}
    string getBioLab() {return bioLab;}
    string getAgeLab() {return ageLab;}
    string getMatchPercentLab() {return matchPercentLab;}
    void read_lab(char *mem);
    void read_from(char *mem);
    void write_to(char *mem);
    void update();
};

void display( State &state);

#endif
