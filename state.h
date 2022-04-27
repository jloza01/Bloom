#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
    Account &potmatch;
    int percentMatch, numFields;
    string name, bio;
    char showPopUp, pageTitle, popUpText;

    //showPopUp: 0- no pop up, 1- y/n pop up, 2- enter text pop up
    //pageTitle: M- main page, L- chat list, C- user chat
    //popUpText: S- same match, M- more than friends, J- just friends, B- block user, R- report user, E- explain

    public:
    char getShowPopUp() const {return showPopUp;}
    int getPercentMatch() const {return percentMatch;}
    int getAge() const{return age;}
    int getnumMatches() const {return numMatches;}
    int offsetOf(int index) const;
    string getPageTitle() const {return pageTitle;}
    string getPopUpText()const{return popUpText;}
    string getName() const{return name;}
    string getBio() const{return bio;}
    void read_from(const char *mem);
    void write_to(char *mem);
};


void display(const State &state);

#endif
