#ifndef __MATCH_H__
#define __MATCH_H__
#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/show_mem.h"
#include <ctime>
#include "user.h"
using namespace std;

class match{
  string email1;
  string email2;
  char ans1; // n- swipe left l- romantic relationship f-friendship for first user
  char ans2; // y or n for first user
  char ans3; // n l or f for 2nd user
  char ans4; // y or n for 2nd user
  

  match(){
    set_email1("0");
    set_email2("0");
    set_ans1('0');
    set_ans2('0');
    set_ans3('0');
    set_ans4('0');
  }

  match(string eml, char ans1){
    set_email1(eml);
    set_email2("0");
    set_ans1(ans1);
    set_ans2('0');
    set_ans3('0');
    set_ans4('0'); 
  }

  public:
  char get_ans1();
  char get_ans2();
  char get_ans3();
  char get_ans4();
  char get_email1();
  char get_email2();
  void set_ans1(a1);
  void set_ans2(a2);
  void set_ans3(a3);
  void set_ans4(a4);
  void set_email1(em1);
  void set_email2(em2);
  char checkIfUserAns(eml);
  bool checkIfMatch();
};

#endif