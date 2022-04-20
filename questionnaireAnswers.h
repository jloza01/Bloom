#ifndef __QuestionnaireAnswers_H__
#define __QuestionnaireAnswers_H__

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//stores the user's answer to the questionnaire
class QuestionnaireAnswer{
    char multChoice[10];
    string shortAns[3], username;

    public:
    //constructor
    QuestionnaireAnswer(){};
    
    //setters
    void setMultChoice(int questionNum, char ans){};
    void setShortAns(int questionNum, string ans){};

    //getters
    char getMultChoice(int questionNum) const{};
    string getShortAns(int questionNum) const{};

    //prints the answers to all the questions
    void printAns(){};

};

#endif