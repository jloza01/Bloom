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
    QuestionnaireAnswer(){
      for(int i = 0; i < 10; i++){
        multChoice[i] = '.';
      }
      for(int i = 0; i < 3; i++){
        shortAns[i] = ".";
      } 
    }
    
    //setters
    void setMultChoice(int questionNum, char ans){
      multChoice[questionNum-1] = ans; //-1 since multAns is indexed at 0
    }
    void setShortAns(int questionNum, string ans){
      shortAns[questionNum-1] = ans; //-1 since shortAns is indexed at 0
    }

    //getters
    char getMultChoice(int questionNum) const{
      return multChoice[questionNum-1]; //-1 since multAns is indexed at 0
    }
    string getShortAns(int questionNum) const{
      return shortAns[questionNum-1]; //-1 since shortAns is indexed at 0
    }

    //prints the answers to all the questions
    void printAns(){
      for(int i = 0; i < 10; i++){
        cout << "Multiple Choice " << i+1 << ": " << multChoice[i] << endl;
      }
      for(int i = 0; i < 3; i++){
        cout << "Short Answer " << i+1 << ": " << shortAns[i] << endl;
      }
    }

};

//reads the questionnaire in from a file and prints them out
class QuestionnaireQuestions{
  ifstream myFile;
  string line, username;

  public:
  //default constructor
  QuestionnaireQuestions() : myFile("NOFILE.txt"), line("NA"){}

  //prints the context of specific file
  void printFromFile(string fileName){
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
  void printMultChoice(){
      printFromFile("Questionnaire.txt");
  }

  //prints the correct 3 short answer questions based on the user's answer to the first question
  void printShortAns(char q1Ans){
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

};

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
  //test_set_getAnswer(); //expected output "c\n a\n"
  //test_getShortAns(); //expected output "I love software design!\n"
  //test_printAns(); //expected output Multiple Choice 1-10: . and Short Answer 1-3: . 
  //test_printQuestionnaire(); //expected output, prints out the entire questionnaire
  //test_printShortAns(); //expected output, 3 sets of short answer questions
}