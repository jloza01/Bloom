#include <iostream>
#include <string>
#include <fstream>
#include "match.h"
using namespace std;

  char match::get_ans1(){
      return ans1;
  }
  char match::get_ans2(){
      return ans2;
  }
  char match::get_ans3(){
      return ans3;
  }
  char match::get_ans4(){
      return ans4;
  }
  string match::get_email1(){
      return email1;
  }
  string match::get_email2(){
      return email2;
  }
  void match::set_ans1(a1){
      ans1 = a1;
  }
  void match::set_ans2(a2){
      ans2 = a1;
  }
  void match::set_ans3(a3){
      ans3 = a3;
  }
  void match::set_ans4(a4){
      ans4 = a4;
  }
  void match::set_email1(em1){
      email1 = em1;
  }
  void set_email2(em2){
      email2 = em2;
  }
  char checkIfUserAns(eml){
      char check; // n- is no answer f- only the first ans is anwered s- second answer is answered
      if(eml == get_email1){
          if(get_ans3()== 0){
            check= 'n';
            return check;
          }
          if (!get_ans3()== 0 && get_ans4()==0){
              check = f;
              return check
          }
          else{
              check = s;
              return s;
          }
      }else{
          if(get_ans1()== 0){
            check= 'n';
            return check;
          }
          if (!get_ans1()== 0 && get_ans2()==0){
              check = f;
              return check
          }
          else{
              check = s;
              return s;
          }
      }

  }
  bool checkIfMatch(){
      bool check;
      if (get_ans1() == get_ans3() || get_ans2() == get_ans4()){
          check = 1;
          return check;
      }else{
          check = 0;
          return check;
      }
  }