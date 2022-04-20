#ifndef __QuestionnaireQuestions_H__
#define __QuestionnaireQuestions_H__

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//reads the questionnaire in from a file and prints them out
class QuestionnaireQuestions{
  ifstream myFile;
  string line, username;

  public:
  //default constructor
  QuestionnaireQuestions(){};

  //prints the context of specific file
  void printFromFile(string fileName){};

  //prints all the multiple choice questions
  void printMultChoice(){};

  //prints the correct 3 short answer questions based on the user's answer to the first question
  void printShortAns(char q1Ans){};

};

#endif