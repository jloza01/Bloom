#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{

    Account &potmatch;
    int percentMatch, numMatches;
    string popUpText, pageTitle;
    char showPopUp;

    public:
    char getShowPopUp() const {return showPopUp;}
    int getPercentMatch() const {return percentMatch;}
    int getnumMatches() const {return numMatches;}
    string getPageTitle() const {return pageTitle;}
    string getPopUpText()const{return popUpText;}
    void read_from(const char *mem);
    void write_to(char *mem);
};


void display(const State &state);

#endif