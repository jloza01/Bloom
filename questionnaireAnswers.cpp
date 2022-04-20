#include <iostream>
#include <string>
#include <fstream>
#include "questionnaireAnswers.h"
using namespace std;

    //constructor
    QuestionnaireAnswer::QuestionnaireAnswer(){
      for(int i = 0; i < 10; i++){
        multChoice[i] = '.';
      }
      for(int i = 0; i < 3; i++){
        shortAns[i] = ".";
      } 
    }
    
    //setters
    void QuestionnaireAnswer::setMultChoice(int questionNum, char ans){
      multChoice[questionNum-1] = ans; //-1 since multAns is indexed at 0
    }
    void QuestionnaireAnswer::setShortAns(int questionNum, string ans){
      shortAns[questionNum-1] = ans; //-1 since shortAns is indexed at 0
    }

    //getters
    char QuestionnaireAnswer::getMultChoice(int questionNum) const{
      return multChoice[questionNum-1]; //-1 since multAns is indexed at 0
    }
    string QuestionnaireAnswer::getShortAns(int questionNum) const{
      return shortAns[questionNum-1]; //-1 since shortAns is indexed at 0
    }

    //prints the answers to all the questions
    void QuestionnaireAnswer::printAns(){
      for(int i = 0; i < 10; i++){
        cout << "Multiple Choice " << i+1 << ": " << multChoice[i] << endl;
      }
      for(int i = 0; i < 3; i++){
        cout << "Short Answer " << i+1 << ": " << shortAns[i] << endl;
      }
    }