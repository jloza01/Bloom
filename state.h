#ifndef __STATE_H__
#define __STATE_H__

#include<string>
using namespace std;

class State{
<<<<<<< HEAD
    int percentMatch, age, numMatches;
    string name, bio;
=======
    int percentMatch, age;
    string name, bio, popUpText;
>>>>>>> 8e89c04554dcfe16523bb954d5f07754ee47d947
    char showPopUp;

    public:
    char getPopUp(){return showPopUp;}
    int getPercentMatch(){return percentMatch;}
    int getAge(){return age;}
<<<<<<< HEAD
    int getnumMatches(){return numMatches;}
=======
    string getPopUpText(){return popUpText;}
>>>>>>> 8e89c04554dcfe16523bb954d5f07754ee47d947
    string getName(){return name;}
    string getBio(){return bio;}
    void read_from(const char *mem);
    void write_to(char *mem);
    void display();
};

#endif