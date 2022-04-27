#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
<<<<<<< HEAD
    Account &potmatch;
    int percentMatch, numFields;
    string name, bio;
    char showPopUp, pageTitle, popUpText;
=======
    int percentMatch, age, numMatches, numFields, bioLength, nameLength, popUpTextLength;
    string name, bio, popUpText;
    char showPopUp, pageTitle;
>>>>>>> bdec78d178f9d2e389a6e0f88a8b724b4fc622f8

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
