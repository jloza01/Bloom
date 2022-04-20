#include <iostream>
#include <string>
#include <fstream>
#include "questionnaireAnswers.h"
#include "questionnaireQuestions.h"
using namespace std;

void test_set_getAnswer(){
  QuestionnaireAnswer ans;
  ans.setMultChoice(4, 'c');
  cout << ans.getMultChoice(4) << endl;
  ans.setMultChoice(9, 'a');
  cout << ans.getMultChoice(9) << endl;
}

void test_getShortAns(){
  QuestionnaireAnswer ans;
  ans.setShortAns(2, "I love software design!");
  cout << ans.getShortAns(2) << endl;
}

void test_printAns(){
  QuestionnaireAnswer ans;
  ans.printAns();
}

void test_printQuestionnaire(){
  QuestionnaireQuestions quest;
  quest.printMultChoice();
}

void test_printShortAns(){
  QuestionnaireQuestions quest;
  cout << "Romantic Questions:" << endl;
  quest.printShortAns('a');
  cout << "Friendship Questions: " << endl;
  quest.printShortAns('b');
  cout << "Hook Up Questions: " << endl;
  quest.printShortAns('c');
}

int main(){
  test_set_getAnswer(); //expected output "c\n a\n"
  test_getShortAns(); //expected output "I love software design!\n"
  test_printAns(); //expected output Multiple Choice 1-10: . and Short Answer 1-3: . 
  test_printQuestionnaire(); //expected output, prints out the entire questionnaire
  test_printShortAns(); //expected output, 3 sets of short answer questions
}