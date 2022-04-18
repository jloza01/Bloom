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
    string firstName;
    string lastName;
    string pronouns;
    int month;
    int day;
    int year;
  public:
    string get_email();
    string get_password();
    string get_school();
    string get_bio();
    string get_firstName();
    string get_lastName();
    string get_pronouns();
    int get_month();
    int get_day();
    int year();
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
};

#endif 