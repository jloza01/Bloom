#ifndef __STATE_H__
#define __STATE_H__

#include<string>
#include "user.h"
#include"message.h"
using namespace std;

class State{
    //match match;
    Account you, potmatch;
    int percentMatch, bioLength, nameLength, popUpTextLength, showPopUp, pageTitle, numMessages=0; int nextMessageInd;
    string popUpText;
 
    


    //labels text
    string yourProfileLab, bioLab, ageLab, matchPercentLab, popUpLab, yesLab, noLab, chatLab, helloLab;
    
    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: 0- main page, 1- chat inbox, 2- user chat

    public:
    //messages
    Message **messages;
    Account &getMatchAccount() {return potmatch;}
    Account &getYourAccount() {return you;}
    int getShowPopUp() {return showPopUp;}
    int getPageTitle()  {return pageTitle;}
    int getPercentMatch()  {return percentMatch;}
    int getNumMessages() {return numMessages;}
    int getNextMessageIndex(){return nextMessageInd;}
    int offset(string text);
    int offsetMessage(int ind);
    string getPopUpText(){return popUpText;}
    string getYourProfileLab() {return yourProfileLab;}
    string getBioLab() {return bioLab;}
    string getAgeLab() {return ageLab;}
    string getMatchPercentLab() {return matchPercentLab;}
    //string getChatContent(){return chatContent;}
    void read_lab(char *mem);
    void read_from(char *mem);
    void write_to(char *mem);
    void read_messages(char *mem);
    void update();
    void setMatch(Account you, Account potMatch);
};

void display( State &state);

#endif
