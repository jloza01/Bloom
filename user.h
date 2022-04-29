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
    int month;
    int day;
    int year;
    int age;

    Account(string eml, string pwd){
      set_email(eml);
      set_password(pwd);
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      numMatches = 0;
      set_month(0);
      set_prounouns("n/a");
      set_year("n/a");
      set_day("n/a");
      set_age("n/a");
    }
      Account(){
      set_email("n/a");
      set_password("n/a");
      set_bio("n/a");
      set_name("n/a");
      matches = 0;
      numMatches = 0;
      set_month(0);
      set_prounouns("n/a");
      set_year("n/a");
      set_day("n/a");
      set_age("n/a");
    }

  public:
    string get_email();
    string get_password();
    string get_school();
    string get_bio();
    string get_firstName();
    string get_lastName();
    string get_pronouns();
    int get_month(); // Need to figure out how to use time library to figure out age
    int get_day();
    int get_year();
    int get_age();
    int get_numMatches();
    void changeAge();
    void set_email(string eml);
    void set_password(string pswd);
    void set_school(string schl);
    void set_bio(string b);
    void set_firstName(string fn);
    void set_lastName(string ln);
    void set_prounouns(string pn);
    void set_month(int m);
    void set_day(int m);
    void set_year(int m);
    void add_match(Account &user);
};

#endif 