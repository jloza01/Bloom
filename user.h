#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <iostream>
#include <cassert>
#include "/usr/local/cs/cs251/react.h"
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
    Account **blocks;
    int numBlocks;
    int numMatches;
    int age;
    string pic;

  public:
    Account(string eml, string pwd){
      set_email(eml);
      set_password(pwd);
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      blocks = 0;
      numMatches = 0;
      numBlocks = 0;
      set_prounouns("n/a");
      set_age(0);
      set_pic("n/a");
    }
    Account(){
      set_email("n/a");
      set_password("n/a");
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      blocks = 0;
      numMatches = 0;
      numBlocks = 0;
      set_prounouns("n/a");
      set_pic("n/a");
      set_age(0);
    }

  
    string get_email();
    string get_password();
    string get_school();
    string get_bio();
    string get_name();
    string get_pronouns();
    string get_pic();
    int get_age();
    int get_numMatches();
    int get_numBlocks();
    string get_matches(int i);
    void set_email(string eml);
    void set_password(string pswd);
    void set_school(string schl);
    void set_bio(string b);
    void set_name(string nm);
    void set_prounouns(string pn);
    void set_age(int a);
    void set_pic(string p);
    void add_match(Account &user);
    void add_block(Account &user);
    void update_numMatches();//adds 1 to num matches
    void update_numBlocks();
};

#endif 