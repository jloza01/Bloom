#include <iostream>
#include <string>
#include <fstream>
#include "questionnaireQuestions.h"
using namespace std;

  //default constructor
  QuestionnaireQuestions::QuestionnaireQuestions() : myFile("NOFILE.txt"), line("NA"){}

  //prints the context of specific file
  void QuestionnaireQuestions::printFromFile(string fileName){
    myFile.open(fileName);
    if(myFile.is_open()){
      while(getline(myFile,line)){
        cout << line << '\n';
      }
    }else{
      cout << "Unable to open file" << endl;
      return;
    }
    myFile.close();
  }

  //prints all the multiple choice questions
  void QuestionnaireQuestions::printMultChoice(){
      printFromFile("Questionnaire.txt");
  }

  //prints the correct 3 short answer questions based on the user's answer to the first question
  void QuestionnaireQuestions::printShortAns(char q1Ans){
    //User is looking for romantic relationship
    if(q1Ans == 'a'){
        printFromFile("romanticQuestions.txt");
    }

    //User is looking for a friendship
    else if(q1Ans == 'b'){
        printFromFile("friendlyQuestions.txt");
    }

    //User is looking for a hook up
    else if(q1Ans == 'c'){
        printFromFile("hookUpQuestions.txt");
    }
    
    //Question 1 Answer is not a,b or c
    else{
      cout << "Invalid Answer to Multiple Choice QUestion 1." << endl;
      return;
    }
    myFile.close();
  }

