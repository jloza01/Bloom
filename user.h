#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/show_mem.h"
#include <ctime>
using namespace std;

class Account{
    string email;
    string password;
    string school;
    string bio;
    string name;
    string pronouns;
    Account **matches;
    int numMatches;
    int age;

    Account(string eml, string pwd){
      set_email(eml);
      set_password(pwd);
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      numMatches = 0;

      set_prounouns("n/a");
      set_age(0);
    }
      Account(){
      set_email("n/a");
      set_password("n/a");
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      numMatches = 0;
      set_prounouns("n/a");
      set_day("n/a");
      set_age("n/a");
    }

  public:
    string get_email();
    string get_password();
    string get_school();
    string get_bio();
    string get_name();
    string get_pronouns();
    int get_age();
    int get_numMatches();
    void set_email(string eml);
    void set_password(string pswd);
    void set_school(string schl);
    void set_bio(string b);
    void set_name(nm);
    void set_prounouns(string pn);
    void set_age(int a);
    void add_match(Account &user);
};

#endif 